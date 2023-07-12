include(cmake/CPM.cmake)

# Done as a function so that updates to variables like
# CMAKE_CXX_FLAGS don't propagate out to other
# targets
function(setup_dependencies)

  # For each dependency, see if it's
  # already been provided to us by a parent project

  if(NOT TARGET CLI11::CLI11)
      CPMAddPackage("gh:CLIUtils/CLI11@2.3.2")
  endif()

endfunction()
