.. _devProcess:

libCellML Development Process
=============================

DRAFT for discussion

By Randall Britten
8 September 2014

See also:

*  Coding style guide (still to be created).

Development process
-------------------
See https://guides.github.com/introduction/flow/ for a comprehensive description of the workflow used for libCellML.  Some additional adaptations are briefly summarised below.
Note: All of the GitHub steps can be done using just a browser and GitHub, which makes it easier for even very small changes to be contributed.

#. Discuss proposed changes

   * Discuss the proposed changes online (at least in part) so that others can contribute.
   * Use any combination of the following "channels":
     * GitHub issue 
     * GitHub pull request from a topic branch
     * Mailing list (cellml-tools-developers@cellml.org).  
     * Face-to-face discussions, Skype/Hangouts, phone calls.  These are exceedingly valuable, and encouraged, but please summarise online.

   * A libCellML developer will create an issue/pull request on behalf of those who for some reason cannot do this themselves, and if necessary, capture discussions elsewhere into the issue/pull request.
   * Remember to search through existing issues first in case a relevant one already exists.

#. Create GitHub issue, and/or branch on your fork and an associated pull request 

   * If you have already created an issue and/or pull request for discussion of the proposal, then skip this step.  Note: directly creating a pull request without first creating an issue perfectly acceptable.

   * The branch label name should be short but descriptive, and it is usually best to suffix it with two digits, "01" for the first time the label is used, and sequential numbering thereafter.

#. Create a pull request

Guidelines:
   * Commit often
   * Strive for each small simple logical change, preferably self contained.
   * Use interactive git change staging if necessary to convert edits that comprise multiple changes into separate commits. Git makes this really easy.
   * Push almost as often as you commit
   * Make commit messages as useful as possible. 

   * Committing message structure guidelines:

     * First line is a brief summary.
     * Optional: Leave second line blank, and then provide more details.
     * Mention any relevant issue numbers

       * Use the qualified/cross-repository syntax (e.g. use "cellml/libcellml#3593 to refer to issue number 3593)
  
     * If you believe that a commit results in an issue being resolved, include e.g. "closes cellml/libcellml#3593" to close issue 3593.  (Unless the qualified/cross-repo syntax is used, the issue only becomes closed when the pull request is merged into the upstream repo.)

#. Tests first

   * Strive to always write unit tests and other tests first. This is so that the tests themselves are validated (they fail until the implementation is done).

#. Get at least one person to review the changes

   * Each reviewer posts review comments to the pull request, but if necessary, first discuss with the contributor privately rather than starting flame wars in the open.
   * Any necessary changes during review are committed and pushed to the branch.
   * A reviewer can also make edits, and commits that can be incorporated into the pull request branch.
   * When each reviewer is satisfied, one of the reviewers should post a comment saying that the pull request can be merged

   * Review Checklist:

     * Coding style followed
     * Code clear and self documenting
     * Sufficient tests
     * Sufficient documentation
     * Code compiles, tests pass


#. A member of the libCellML team that can merge the changes into the main libCellML repository will check that the review is complete and merge the pull request.


Acknowledgements
----------------
* OpenCMISS-Iron developers: There is a draft document describing the process for that project, and that document was used to guide the creation of this document.
