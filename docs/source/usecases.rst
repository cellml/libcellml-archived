.. _libcellmlUseCases:

Use cases
=========

Randall Britten, 25 August 2014

(The roadmoap was used as the starting point for this document, so see there for its contributors.)

Notes:

#. Not necessarily in order of priority, but probably close, since order taken from version of roadmap as at time this doc was created.
#. Some use case descriptions actually describe multiple use cases, and in that case, the line header is "Use cases".
#. Where a use case description describes multiple use cases, it does not mean that all individual use cases share the same priority.

#. Category: Create a CellML 1.2 model from scratch and serialise it to specified format

   #. Use cases for each of the following options for "specified format":

      #. XML
      #. JSON
      #. RDF

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

#. Category: Conversion to intermediate representation

   #. Use case: Conversion to CellML structureless mathematics (just the maths) into an intermediate representation that can be transformed / analysed by other tools. With units.

      #. Notes:

         #. Ability to maintain the CellML structure (as much as possible), perhaps via object annotation (e.g., COR)
         #. Will form the basis for tools using libCellML to perform numerical simulation. See also code generation use case.

#. Category: code generation

   #. Notes:

      #. See also "Conversion to intermediate representation" use case.
      #. Proposed approach: generate procedural code from the intermediate representation
      #. Generic code vs solver specific code.
      #. Could be a role for being informed from SED-ML what solver is to be used and customising generated code appropriately.
      #. Would be a tool sitting on top of libCellML, not directly part of it.

   #. Use cases: Generate code for the following languages (C, MATLAB, Fortran, JavaScript) and the following variations:

      #. CVODE style 1: Initial Value Problem (IVP) Ordinary Differential Equation (ODE) System, no algebraic equations (i.e. truly an ODE system)
      #. CVODE style 2: IVP-ODE with explicit algebraic equations (e.g. y' = a, a = x, x' = b, b = - y). This case has the subtelty that the algebraic calculations need to be rerun over the final solution to get correct "time"-varying values.
      #. IDA style: Differential Albebraic Equation (DAE) system in implicit form (i.e. F(y', y, v, t) = 0 where y and v are a list of real valued "time"-varying quantities (or constants), and usually there is not a trivial transformation to the from of an IVP-ODE with explicit algebraic equations.
      #. All of the preceding variations with the addition of "reset rules", (e.g. if y > k1 then y = k2, etc)


#. Category: support legacy CellML versions

   #. Notes: 

      #. Export to older versions allows the use of model in existing tools (e.g., simulation, annotation, NeSI), 
      #. Preserve model and XML structure/ordering/modularity/annotations where possible.

   #. Use cases: Read in CellML version A model, save as CellML version B, where A and B are:

      ===== =====
      A     B
      ===== =====
      1.1   1.2
      1.0   1.2
      1.2   1.1
      1.2   1.0
      ===== =====

#. Category: Installation for developer of 3rd party software, or scripter, that will use libCellML

   #. Notes: 

      #. native installers (using CPack, pip)
      #. easy to setup build environment (good documentation)
      #. Supported languages and platforms as per lists below.

   #. Use cases for combinations of OS (not cross-compilation) (i.e. Mac OS X, Linux, Windows) and client language (C++, Python, Java, Matlab, JavaScript, C#/.Net, C, Fortran[77|90|20XX])
   #. Use cases for cross-compilation scenarios targetting mobile platforms: applicable combinations of 

      #. Cost OS (i.e. Mac OS X, Linux, Windows)
      #. Client language (C++, Java, Objective-C, Swift?)
      #. Target platform: Android, iOS

   
#. Use case: Access data contained in CellML models in external namespaces (RDF, extensions, etc).

   #. Todo: needs fleshing out


#. Use case: Run simulations with CellML 1.2

   #. Notes:

      #. while not directly part of libCellML, helping tool developers get to the point where they can execute simulations is critically important.
      #. CellML 1.2 will not be released until we can do this (in addition to the other requirements above)


Todo
----

#. Todo: rework the following text from roadmap into the form of use cases, and delete lines that are not use cases.
#. Todo: (Initial planning already mostly done, but some use cases needed fleshing out.) Prioritise the use cases (e.g. as per Rational Unified Process, or eXtreme Programming iteration planning, i.e. between iterations, revise future iteration plans). Todo: put this comment into libCellML project methodology doc.


The following is Text copied from roadmap and will still be digested into use case itemisation
----------------------------------------------------------------------------------------------

#. Provide an events system to monitor changes in the model

#. High order model manipulation (recall discussion with Andrew McCulloch at the 8th workshop)
   
   #. again, outside core libCellML, but helping tool developers provide these kinds of services is very important.

