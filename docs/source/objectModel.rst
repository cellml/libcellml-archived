.. _libcellmlObjectModel:

libCellML Object Model
=================

Randall Britten, 26 August 2014


Introduction
------------
The object model is (currently) a very high level conceptual design.


Conventions
-----------
UML images are created using Eclipse/Papyrus. Some detail may not show in the diagrams, or be explained in this text, so if you are in doubt, please refer to the model details in Eclipse/Papyrus.
Collections are often indicated as an association from one class to another (or the same class if the containment is recursive) on a class diagram.  At this stage, methods for adding and removing from the collection are omitted from the diagram.
Often, some of the member operations and properties of a class are hidden on some of the diagrams on which it appears.  Also, a class may be shown multiple times on the same diagram.

Remember to pay attention to the arrows indicating navigability of associations, as well as the cardinality of the association ends.

Overview of object model
------------------------
.. figure:: /imageExports/libCellML_01_01.PNG

Shown in this overview:
#.  A model has a collection of components and a collection of units.
#.  A component has a collection of variables, and a collection of "Maths" objects.  This design does not yet have any details for how maths is represented, it will probably be the abstract syntax tree (AST) of the MathML.
#.  A component also has a collection of the units defined within the component.


Details for variable object model
---------------------------------
.. figure:: /imageExports/Variable.PNG

#.  Variables may be real or boolean.  (Real is taken to mean that the codomain is real.  Thus state variables are treated as real variables, even though they are actually real valued functions of the variable of integration (VOI). Constant real values fall into this category (i.e. real is isomorphic to () → ℝ, where () is the nullary cartesian product).
#. Only real variables have units.
#. Varibles have a collection (which may be empty) of the variables to which they are connected. Note that this is not normalised at this conceptual level, (i.e. From A you can see B in the list of connected variables, and from B you can see A in the set of connected variables.  Nevertheless, the implementation is likely to be normalised, and the XML representation likewise will have a normalised representation, where a connection element indicates that A is connected to B.
