module RationaliseGroupedManyToMany where

-- Aims to prototype the algorithm for rationalising a many-to-many relationship between to objects (here its Variable--Variable)
-- Into a one--many--one
-- With the added caveat that each object is owned, and the one--many--one listing must be grouped by the owner (in this example, the owner is Component).
-- The collection of all owners is Model in this case.
-- This code was created to serve as a guide for creating the equivalent C++ code for the libCellML project.


import Data.List
import Data.Set (Set)
import qualified Data.Set as S 
import Data.Map.Strict (Map)
import qualified Data.Map.Strict as M 
import Data.Maybe

data Component = Component {cname :: String, cvars :: [Variable]} deriving (Eq, Ord)

instance Show Component where
  show = cname

data Variable = Variable {vname :: String, parent :: Component, vconnections :: [Variable]}

instance Show Variable where
  show = vname

instance Eq Variable where
  (Variable v1name v1parent _) == (Variable v2name v2parent _) = v1name == v2name && cname v1parent == cname v2parent -- Optimistically assumes no duplicate names used.

instance Ord Variable where
  (Variable v1name v1parent _) <= (Variable v2name v2parent _) = v1name <= v2name && cname v1parent <= cname v2parent -- Optimistically assumes no duplicate names used.

type Model = [Component]


-- Rationalise connections

cvPairs :: Variable -> [CvPair]
cvPairs v1 = map (cvPair v1) (vconnections v1)

cvPair :: Variable -> Variable -> (Set Component, Set Variable) -- With 1 or 2 elements in each set (1 in the case where redundant self connection is made (v--v) or connection within same component (c.v1--c.v2))
cvPair v1 v2 = (S.fromList [parent v1, parent v2], S.fromList [v1, v2])

componentCvps :: Component -> [CvPair]
componentCvps c = concatMap cvPairs (cvars c)

modelCvps :: Model -> [CvPair]
modelCvps = concatMap componentCvps

type CvPair = (Set Component, Set Variable)
type ConnectionSetMap = Map (Set Component) (Set (Set Variable))

addCvpToMap :: CvPair -> ConnectionSetMap -> ConnectionSetMap
addCvpToMap cvp m = M.insert k newSetOfVPairs m
  where
    k = fst cvp
    oldSetOfVPairs = fromMaybe S.empty (M.lookup k m)
    vPair = snd cvp
    newSetOfVPairs = S.insert vPair oldSetOfVPairs

modelToConnectionsSet :: Model -> ConnectionSetMap
modelToConnectionsSet = foldr addCvpToMap M.empty . modelCvps

-- Construct a test model
c1 :: Component
c1 = Component {cname="c1", cvars=[v11, v12]}

v11 :: Variable
v11 = Variable {vname="v11", parent=c1, vconnections=[v12, v21]}

v12 :: Variable
v12 = Variable {vname="v12", parent=c1, vconnections=[v11, v22]}


c2 :: Component
c2 = Component {cname="c2", cvars=[v21, v22]}

v21 :: Variable
v21 = Variable {vname="v21", parent=c2, vconnections=[v11]}

v22 :: Variable
v22 = Variable {vname="v22", parent=c2, vconnections=[v12]}


m1 :: Model
m1 = [c1, c2]


-- Rationalised connections for model
     
mcs = modelToConnectionsSet m1
