/*
 * @BEGIN LICENSE
 *
 * Psi4: an open-source quantum chemistry software package
 *
 * Copyright (c) 2007-2018 The Psi4 Developers.
 *
 * The copyrights for code used from other parties are included in
 * the corresponding files.
 *
 * This file is part of Psi4.
 *
 * Psi4 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * Psi4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with Psi4; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * @END LICENSE
 */

#include "psi4/pybind11.h"

#include "psi4/libefp_solver/efp_solver.h"
#include "psi4/liboptions/liboptions.h"

using namespace psi;
using namespace psi::efp;

void export_efp(py::module& m) {
    // because there is no default constructor for libefp, need flag
    // "no_init" and the constructor definition, def(init<Options&>())
    py::class_<EFP, std::shared_ptr<EFP> >(m, "EFP", "Class interfacing with libefp")
        .def(py::init<Options&>())
        .
#ifdef USING_libefp
        def("compute", &EFP::compute, "Computes libefp energies and, if active, torque")
        .def("set_qm_atoms", &EFP::set_qm_atoms, "Provides libefp with QM fragment information")
        .def("print_out", &EFP::print_out, "Prints options settings and EFP and QM geometries")
        .
#endif
        def("nfragments", &EFP::get_frag_count,
            "Returns the number of EFP fragments in the molecule");
}
