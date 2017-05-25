cmake_minimum_required(VERSION 3.0)
project(fuse-cpp-ramfs)

if(WIN32)
  set(SHAREDIR ".")
  set(DOCDIR "doc")
elseif(APPLE)
  set(SHAREDIR "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}")
  set(DOCDIR "share/doc/${PROJECT_NAME}")
  set(MANDIR "share/man")
elseif(UNIX) # Linux, BSD etc
  set(SHAREDIR "share/${PROJECT_NAME}")
  set(DOCDIR "share/doc/${PROJECT_NAME}")
  set(MANDIR "share/man")
endif()


add_subdirectory(src)
add_subdirectory(doc)

#install(DIRECTORY sample_data DESTINATION "${SHAREDIR}")
