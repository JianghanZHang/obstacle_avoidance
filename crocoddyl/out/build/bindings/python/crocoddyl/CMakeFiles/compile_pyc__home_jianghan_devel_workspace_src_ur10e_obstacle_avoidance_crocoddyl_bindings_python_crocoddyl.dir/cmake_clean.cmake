file(REMOVE_RECURSE
  "./__init__.pyc"
  "./deprecated.pyc"
  "utils/__init__.pyc"
  "utils/biped.pyc"
  "utils/pendulum.pyc"
  "utils/quadruped.pyc"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/compile_pyc__home_jianghan_devel_workspace_src_ur10e_obstacle_avoidance_crocoddyl_bindings_python_crocoddyl.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
