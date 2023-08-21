"""Arch documentation build configuration file."""

import pathlib

# -- General ------------------------------------------------------------------

extensions = ["sphinxcontrib.doxylink"]
templates_path = ["_templates"]
source_suffix = ".rst"
master_doc = "index"

project = "Pixar Arch"
copyright = "2024, Pixar, modified by Jeremy Retailleau"

build_path = pathlib.Path("@CMAKE_CURRENT_BINARY_DIR@/doc/pxr/arch")
doxylink = {"arch-cpp": ((build_path / "pxr-arch.tag").as_posix(), "./doxygen")}
add_function_parentheses = True

# -- HTML output --------------------------------------------------------------

html_theme = "sphinx_rtd_theme"
html_favicon = "favicon.ico"
html_show_sphinx = False
