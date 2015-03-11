.. _Developer Contribution for libCellML:

=================
Contributing Code
=================

This section describes how to contribute to the libCellML project.  While there are many types of contribution, this section focuses on code and documentation contributions (and contributions of any other digital assets that are managed using the version control system).  We recommend that you have first read :doc:`Setup <libcellml-development-setup>`. 

.. contents:

Overview
========

An issue is used to initiate work and for overall discussion.  A pull request is created and referenced from the issue.

Reviewers provide feedback on the changes by adding comments to the pull request or associated commits. The BuildBot build/test procedure will run each time changes are pushed to the pull request's branch, and the results are displayed in the pull request view.

Once all the changes and reviews are complete, one of the prime repository owners will merge the pull request into the prime repository, onto the develop branch.

Note that a bug is just a type of issue, and that resolving the bug requires both a test that triggers the bug, as well as the implementation of the fix.

Issue Assignment
================

If an issue has not been created for the required work (e.g. implementation of a feature, fixing of a bug), then create a new one. To assign yourself to the issue, leave a comment on the issue to that effect.


Pull Request Collaboration
==========================

Pull the latest changes from the develop branch.  Create a branch with a name that briefly describes the work, based off the head of develop. This will be referred to as the topic branch.

For code changes, an automated test should be the first code written and committed.  

After the first commit, push to GitHub so that your work can be shared with others.

Next, create a pull request from your topic branch targeting the prime repository's develop branch.  On the issue, post a comment with a reference to the pull request.  To reference the pull request from the issue in the GitHub comment area, type a hash, "#". A list will appear, from which you can select the pull request. The mark-up for creating the reference will then be automatically added.

Once the work is ready for review, post a comment to the original issue requesting a review, including a reference to the pull request.
GitHub sends notification to those subscribed to the issue and they will review the work, posting feedback on the commits within the pull request, or on the pull request itself.  Respond to this feedback as appropriate, e.g. making coding changes, posting a reply, etc.  Comments are also welcome earlier, since reviewers can see the work on the pull request from the start.  We are striving for a friendly atmosphere of social coding where developers can offer each other guidance and help.

Sometimes it can take more than one pull request to resolve an issue, and not all pull requests will be merged, some my be closed without being merged. 

Test Driven Development
=======================

Test driven development entails writing code that automatically tests the implementation before writing the implementation itself.  Running the tests prior to writing the implementation should cause the tests to fail, and running them after the implementation has been written should cause them to then pass.  This helps validate that the tests cover the required behaviour.  It is common to find that the initial implementation was incomplete (e.g. didn't cover all cases), but nevertheless, the tests didn't detect this.  This is addressed by improving the tests first, and then improving the implementation.  It can often take multiple cycles of modifying tests and implementation to complete the work.  Commit the code changes each time the tests are incrementally improved, and each time the implementation code passes the tests, or more often if necessary.

Refactoring means improving the code without adding features, and the automated tests provide validation that the refactored code performs as well as before.

Completion of Workflow
======================

Once the owners of the prime repository are satisfied that the work on the issue is complete and that the feedback has been addressed, one of the owners will post a comment on the issue notifying subscribers that they intend to merge the pull request.  After allowing a suitable amount of time for any objections to be raised, and if none are raised, the owner will merge and close the pull request, and if no further work is required to resolve the issue, they will close the issue, stating that it has been resolved.
