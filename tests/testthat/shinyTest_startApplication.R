context("startApplication")
# This file is for testing the applications in the apps/ directory.

library(shinytest)

test_that("startApplication() works", {
  # Don't run these tests on the CRAN build servers
  skip_on_cran()
  
  # Use compareImages=FALSE because the expected image screenshots were created
  # on a Mac ..., and they will differ from screenshots taken on the CI platform,
  # which runs on Linux.
  expect_pass(testApp(file.path(testthat::test_path(), "startApplication"), compareImages = FALSE))
})
