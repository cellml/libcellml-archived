.. _libcellmlUseCases:

Use cases
=================

Randall Britten, 25 August 2014

(The roadmoap was used as the starting point for this document, so see there for its contributors.)

Not necessarily in order of priority, but probably close, since order taken from version of roadmap as at time this doc was created.

#. Category: Create a CellML 1.2 model from scratch and save it to XML
   #. Use Case: With only built-in units, only one component, (i.e. no imports, or connections)
   #. Use Case: With only built-in units, multiple components with connections, no imports
   #. Use Case: With user-defined units, no imports
   #. Etc, see http://goo.gl/m9buUi
   #. For each of the above, as relevant: 
      #. create a new model, add imports, components, variables, and math.
   
#. Category: Load a CellML 1.2 model, make changes, save it.
   #. Required feature: preserve underlying XML structure/ordering for documents read in and written out.
   #. Listing below lists the changes made to the model between load and save.
   #. Use case: Rename something (e.g. Model, or component.  Same usage below)
   #. Use case: Add something
      #. Use case: connect variables that were not previously connected (in effect adding a connection)
   #. Use case: Delete something
      #. Use case: disconnect variables that were previously connected (in effect removing a connection)
   #. Use case: Change units of an algebraic identifier
   #. Use case: Change units of a literal constant
   #. todo: add more here

#. Category: Refactoring a CellML 1.2 model
   #. Use cases: rename some item, and corresponding references to that item get renamed, where "some item" is any of:
      #. Variable of a component (renames include ci's in maths)
      #. Component
      #. Unit
      #. Local name of imported component
   #. Rename across imports: Rename some item in one file, and automatic renames cascade to references in imported or importing files. Need to define scope of files that can be changed in this way

#. Use case: Conversion of numerical value in units A to value in compatible units B.

#. Use case: Load XML, reformat it with standard indentation, save result.

#. Category: Validate a CellML 1.2 model
   #. Use case: detect invalid mathematics. For 1.2, the actual restricted subset of mathml from the secondary spec is needed.
   #. Use case: detect units errors. Again, the actual restricted subset of mathml from the secondary spec is needed.

   #. todo: add more here
   #. Required feature: libCellML should have a validation framework based on the core specification and then secondary specs can add their specific rules

#. Use case: list symbol nature

   #. Nature is one of:

      #. Variable of integration (VOI)
      #. Constant set to literal value
      #. Constant determined from algebraic expression, all terms of which are constant
      #. State variable
      #. Algebraic variable
      #. Boolean constant (? depends on spec handling of events)
      #. Boolean variable (? depends on spec handling of events)
      #. "Built-in" function (e.g. sin, exp, +, >) 
      #. User defined function (if CellML ever permits that in future)
      #. todo: add more here

#. Category: code generation
   #. Use cases: Generate code for the following variations
      #. CVODE style 1: Initial Value Problem (IVP) Ordinary Differential Equation (ODE) System, no algebraic equations (i.e. truly an ODE system)
      #. CVODE style 2: IVP-ODE with explicit algebraic equations (e.g. y' = a, a = x, x' = b, b = - y). This case has the subtelty that the algebraic calculations need to be rerun over the final solution to get correct "time"-varying values.
      #. IDA style: Differential Albebraic Equation (DAE) system in implicit form (i.e. F(y', y, v, t) = 0 where y and v are a list of real valued "time"-varying quantities (or constants), and usually there is not a trivial transformation to the from of an IVP-ODE with explicit algebraic equations.
      #. All of the preceding variations with the addition of "reset rules", (e.g. if y > k1 then y = k2, etc)
 
#. Todo: rework the following text from roadmap into the form of use cases, and delete lines that are not use cases.
#. Todo: (Initial planning already mostly done, but some use cases needed fleshing out.) Prioritise the use cases (e.g. as per Rational Unified Process, or eXtreme Programming iteration planning, i.e. between iterations, revise future iteration plans). Todo: put this comment into libCellML project methodology doc (still to be started at time of writing this).


The following is Text copied from roadmap and will still be digested into use case itemisation.
===============================================================================================

#. Import CellML 1.0/1.1 models.

#. Export to CellML 1.1 in order to use model in existing tools (e.g., simulation, annotation, NeSI), preserving model and XML structure/ordering/modularity where possible.

#. Install libCellML on: OS X, Linux, Windows
   
   #. native installers (using CPack, pip)
   #. easy to setup build environment (good documentation)

#. Language support: C++, Python, Java, Matlab

#. Conversion to intermediate representation
   
   #. Conversion to CellMLstructureless mathematics (just the maths) into an intermediate representation that can be transformed / analysed by other tools. With units.
   #. Ability to maintain the CellML structure (as much as possible), perhaps via object annotation (e.g., COR)
   #. Will form the basis for tools using libCellML to perform numerical simulation.

#. Provide an events system to monitor changes in the model
   #. provide access to data contained in CellML models in external namespaces (RDF, extensions, etc).


#. Establish the process/API required to generate procedural code from the intermediate representation

   #. Generic code vs solver specific code.
   #. Could be a role for being informed from SED-ML what solver is to be used and customising generated code appropriately.
   #. Would be a tool sitting on top of libCellML, not directly part of it.

#. Being able to run simulations with CellML 1.2

   #. while not directly part of libCellML, helping tool developers get to the point where they can execute simulations is critically important.
   #. CellML 1.2 will not be released until we can do this (in addition to the other requirements above)

Milestone 4: advanced capabilities (timeframe: ? months)
--------------------------------------------------------

#. High order model manipulation (recall discussion with Andrew McCulloch at the 8th workshop)
   
   #. again, outside core libCellML, but helping tool developers provide these kinds of services is very important.

Milestone 5: broadening accessibility (timeframe: ? months)
-----------------------------------------------------------

#. Support for more platforms

   #. Android, iOS

#. and languages
   
   #. JS, C#/.NET, C, Fortran[77|90|20XX]

