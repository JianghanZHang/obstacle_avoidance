file(REMOVE_RECURSE
  "./test_actions.pyc"
  "./test_actuations.pyc"
  "./test_contacts.pyc"
  "./test_copy.pyc"
  "./test_costs.pyc"
  "./test_impulses.pyc"
  "./test_shooting.pyc"
  "./test_solvers.pyc"
  "./test_squashing.pyc"
  "./test_states.pyc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/compile_pyc__home_jianghan_devel_workspace_src_ur10e_obstacle_avoidance_crocoddyl_unittest_bindings.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
