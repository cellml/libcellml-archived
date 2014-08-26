.. _libcellmlObjectModel:

libCellML Object Model
=================

Randall Britten, 26 August 2014


Introduction
------------
The object model is (currently) a very high level conceptual design. The focus has been on a design to support the initial use case from the roadmap (i.e. Create model, save as XML.  An "isValid" method does not yet exist in the design, since the "validate" use case follows later).


Preamble
--------
UML images are created using Eclipse/Papyrus. Some detail may not show in the diagrams, or be explained in this text, so if you are in doubt, please refer to the model details in Eclipse/Papyrus.
Collections are often indicated as an association from one class to another (or the same class if the containment is recursive) on a class diagram.  At this stage, methods for adding and removing from the collection are omitted from the diagram.
Often, some of the member operations and properties of a class are hidden on some of the diagrams on which it appears.  Also, a class may be shown multiple times on the same diagram.

Remember to pay attention to the arrows indicating navigability of associations, as well as the cardinality of the association ends.

It was realised recently that some cases where UML classes have been specified should perhaps be interfaces.


Overview of object model
------------------------
.. figure:: /imageExports/libCellML_01_01.PNG

Shown in this overview:
#.  A model has a collection of components and a collection of units.
#.  A component has a collection of variables, and a collection of "Maths" objects.  This design does not yet have any details for how maths is represented, it will probably be the abstract syntax tree (AST) of the MathML.
#.  A component also has a collection of the units defined within the component.

Model class
-----------
.. figure:: /imageExports/Model_Class.PNG

#. getXML returns the XML serialisation for the model as text (alternate representations should be considered, e.g. AST or DOM).
#. addImport creates the Import object with just the URL provided as a string.


Details for variable object model
---------------------------------
.. figure:: /imageExports/Variable.PNG

#.  Variables may be real or boolean.  (Real is taken to mean that the codomain is real.  Thus state variables are treated as real variables, even though they are actually real valued functions of the variable of integration (VOI). Constant real values fall into this category (i.e. real is isomorphic to () → ℝ, where () is the nullary Cartesian product).
#. Only real variables have units.
#. Variables have a collection (which may be empty) of the variables to which they are connected. Note that this is not normalised at this conceptual level, (i.e. From A you can see B in the list of connected variables, and from B you can see A in the set of connected variables.  Nevertheless, the implementation is likely to be normalised, and the XML representation likewise will have a normalised representation, where a connection element indicates that A is connected to B.

Encapsulation
-------------
.. figure:: /imageExports/Encapsulation.PNG

#. A component object has a collection of components that are encapsulated by it.  This is recursive.  Note: the design allows for cycles, but the spec does not.

Units of measure
----------------
.. figure:: /imageExports/Units_of_measure.PNG

#. The base class has a property for the unit name, and a boolean flag to indicate whether the unit is built-in.
#. Units may be either base units or derived units.  
#. A derived unit has a collection of "UnitsReference" objects that represent the definition of the derived unit.


Stand alone methods
-------------------
Methods not shown on UML yet, but would be useful.
#. getBuiltinUnits() : [Unit] - returns a collection of the built-in units.

Todo
----
#. Some documentation of classes, operations etc in this document probably belong as documentation in the Papyrus model, and eventually as the Doxygen comments on the C++ code, Python docs, Java docs etc.
#. Details of math representation an utilities
#. Details of XML representation and utilities
#. Change classes to interfaces where appropriate
