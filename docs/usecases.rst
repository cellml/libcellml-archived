
=======================
Use-cases for libCellML
=======================

1. **Create:** Create a model from scratch and serialise it to XML (in each case the test is that the serialised model matches manually validated XML documents)

   a. an empty model
   #. a model with a valid name
   #. a model with an invalid name
   #. a model with a single component
    
      i. a component with a valid name
      #. a component with an invalid name
      
   #. a model with two or more components
   #. a model with three components and an encapsulation hierarchy

      i. one component encapsulating two children
      #. one component encapsulating a single child which in turn encapsulates a single child
      #. an invalid cyclical encapsulation hierarchy

   #. a model with imported components

      i. import the component from model 1.d.i
      #. import the component from model 1.d.ii
      #. import a component from a non-existing URL

   #. a model with units

      i. a single base units with valid name
      #. a single base units with an invalid name
      #. a units which defines micro-Ampere * Kelvin / milli-siemens
      #. the units from 1.h.i and 1.h.iii and multiplies them

   #. a model with imported units

      i. import the units from model 1.h.iii

         #. with a valid name
         #. with an invalid name

      #. import a units from a non-existing URL
      #. import the units from model 1.h.iv and scale it by a factor of 1000
      
   #. a model with variables
   
      #. model from 1.d.i and define a variable with a valid name and units dimensionless
      #. model from 1.d.i and define a variable with an invalid name and units dimensionless
      #. model from 1.d.i and define a variable with a valid name and invalid units name.
      #. model from 1.f.i, define a single variable in each component with units dimensionless
      
         #. private interface in the parent and public interface in the child components and connect the variable in both children to the parent.
         #. public interface in all components and connect the variables in the children to the parent
         
   #. a model with maths and variables
   
      #. … to be added to ...
      
   #. a model with maths, variables and connections
   
      #. … to be added to ...
   
#. **Load and validate:** Load each of the models and validate them (the test is that the models are correctly identified as valid or invalid, and for the case when they are invalid the correct reason is given)
   
#. **Modify:** Modify each of the models from 1.

   a. add {components, units, maths, variables, connections}
   #. remove {components, units, maths, variables, connections}
   #. update {components, units, maths, model attributes, variables, connections}
   
#. Import CellML 1.0/1.1 models

#. Export CellML 1.1 (and by extension CellML 1.0)
