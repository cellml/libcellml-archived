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


Share Progress
==============

We are following a test driven approach for the LibCellML project so the first thing to do is write a test that at least covers some part of the functionality required for the feature you are working on.  Once this first test is written commit your changes and push them to Github so that your work can be shared with others.

When the first new test is pushed to Github create a pull request from your feature/develop branch against the cellml/libcellml repositories develop branch.  We do this so that other developers can comment and make suggestions on your changes.  We want to have an environment of friendly social coding where developers can offer guidance and help minimise wasted effort.  Link this pull request to the main pull request by adding a comment on the main pull request with the following markup::

    cellml/libcellml-tests#4
    
or::
 
    cellml/libcellml-tests/pull/4

Github will interpret this markup and create a link between the pull requests.  Obviously replace the numeral '4' with the actual value of the related pull request for your own work.

With the tests written and any comments from the community resolved write the implementation code, the implementation code is written into your copy of the mapclient-src repository.  Again commit your code and push the changes to Github.  With the new code on Github create another pull request from your repository to the develop branch in the cellml/libcellml-src repository.  Link this pull request to the main pull request again by adding a comment on the main pull request with the following markup::

    cellml/libcellml-src#4
    
or::
 
    cellml/libcellml-src/pull/4

Again, obviously replace the numeral '4' with the actual value of the related pull request for your own work.

Simarlarly to writing the implementation code you also need to write documentation for your changes and create a pull request from your mapclient-docs repository to cellml/libcellml-docs develop branch.  Also link the pull request to the pull request already added for the tests by adding a comment on the main pull request with the following markup::

    cellml/libcellml-docs#4
    
or::
 
    cellml/libcellml-docs/pull/4

Again, replace the numeral '4' with the actual value of the related pull request for your own work.

To have your progress tested push a commit to the main pull request with the correct submodule references set making sure that the dependent pull requests (tests, src, docs) have the commits you are referencing.  When the commit is received by Github Buildbot will be notified and check for any changes, clone and run the tests across the Buildslaves.  When the tests have completed the status will be reported back to the main pull request and the commit status will be made visible on Github.

Final Review
============

When you have finished working on an issue, mark it as closed.  This will indicate to a reviewer that your work is ready for merging.  A reviewer will give your work a final review and when any queries are satisfactorily resolved they will merge and close the three open pull requests across mapclient-{tests, src, docs} and then close the main pull request.  All that is left to do now is to thank you for your contribution.

Thank you.

