file(REMOVE_RECURSE
  "doc/crocoddyl.doxytag"
  "doc/doxygen-html"
  "doc/doxygen.log"
  "CMakeFiles/generate-template-css"
  "doc/doxygen.css"
  "doc/footer.html"
  "doc/header.html"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/generate-template-css.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
