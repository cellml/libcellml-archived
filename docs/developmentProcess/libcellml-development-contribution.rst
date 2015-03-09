.. _Developer Contribution for LibCellML:

=================
Contributing Code
=================

This section describes how to contribute to the LibCellML project.  While there are many types of contribution, this section focuses on code and documentation contributions (and contributions of any other digital assets that are managed using the version control system).  We recommend that you have first read :doc:`Setup <libcellml-development-setup>`. 

.. contents:

Overview
========

An issue is used to initiate work.  Once work has started, a pull request takes over as the way to capture both the discussion, as well as the commits of the changes that are made as the work progresses.  The pull request is from the topic branch of the contributor's fork, and targets the develop branch of the prime repository.

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

Next, create a pull request from your topic branch targeting the prime repository's develop branch.  This allows other developers to comment and make suggestions on your work.  Link this pull request to the issue by adding a comment on the pull request that references the issue. This causes GitHub to automatically create the corresponding reference in the other direction, i.e. from the issue to the pull request.
    
To reference the issue from the pull request in the GitHub comment area, type a hash, "#". A list will appear, from which you can select the issue. The mark-up for creating the reference will then be automatically added.

We want to have an environment of friendly social coding where developers can offer guidance and help.  Other developers will have been notified via GitHub of the work on the pull request, and will review the work, posting feedback on the commits within the pull request, or on the pull request itself.  Respond to this feedback as appropriate, e.g. making coding changes, posting a reply, etc.

Test Driven Development
=======================

Test driven development entails writing code that automatically tests the implementation before writing the implementation itself.  Running the tests prior to writing the implementation should cause the tests to fail, and running them after the implementation has been written should cause them to then pass.  This helps validate that the tests cover the required behaviour.  It is common to find that the initial implementation was incomplete (e.g. didn't cover all cases), but nevertheless, the tests didn't detect this.  This is addressed by improving the tests first, and then improving the implementation.  It can often take multiple cycles of modifying tests and implementation to complete the work.  Commit the code changes each time the tests are incrementally improved, and each time the implementation code passes the tests, or more often if necessary.

Refactoring means improving the code without adding features, and the automated tests enable the refactored code to be validated.

Final Review
============

When you have finished working on an issue, mark it as closed.  This will indicate to a reviewer that your work is ready for merging.  A reviewer will give your work a final review and when any queries are satisfactorily resolved they will merge and close the three open pull requests across mapclient-{tests, src, docs} and then close the main pull request.  All that is left to do now is to thank you for your contribution.

Thank you.

