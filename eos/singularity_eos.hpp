//------------------------------------------------------------------------------
// © 2021. Triad National Security, LLC. All rights reserved.  This
// program was produced under U.S. Government contract 89233218CNA000001
// for Los Alamos National Laboratory (LANL), which is operated by Triad
// National Security, LLC for the U.S.  Department of Energy/National
// Nuclear Security Administration. All rights in the program are
// reserved by Triad National Security, LLC, and the U.S. Department of
// Energy/National Nuclear Security Administration. The Government is
// granted for itself and others acting on its behalf a nonexclusive,
// paid-up, irrevocable worldwide license in this material to reproduce,
// prepare derivative works, distribute copies to the public, perform
// publicly and display publicly, and to permit others to do so.
//------------------------------------------------------------------------------

#ifndef EOS_SINGULARITY_EOS_HPP_
#define EOS_SINGULARITY_EOS_HPP_

#include "eos.hpp"
#include "../mix/mixed_cell_models.hpp"

using singularity::EOS;

#if defined(__cplusplus)
extern "C" {
#endif

int init_sg_eos(const int nmat, EOS* &eos);

int init_sg_IdealGas(const int matid, EOS* eos, const double gm1,
                     const double Cv);

int init_sg_JWL(const int matindex, EOS* eos, const double A,
                const double B, const double R1, const double R2,
                const double w, const double rho0, const double Cv);

int init_sg_Gruneisen(const int matid, EOS* eos, const double C0,
                      const double s1, const double s2, const double s3,
                      const double G0, const double b, const double rho0,
                      const double T0, const double P0, const double Cv);

int init_sg_DavisProducts(const int matid, EOS* eos, const double a,
                          const double b, const double k, const double n,
                          const double vc, const double pc, const double Cv,
                          const double E0);

int init_sg_DavisReactants(const int matid, EOS* eos, const double rho0,
                           const double e0, const double P0, const double T0,
                           const double A, const double B, const double C,
                           const double G0, const double Z, const double alpha,
                           const double Cv0);

#ifdef SPINER_USE_HDF
int init_sg_SpinerDependsRhoT(const int matid, EOS* eos,
                              const char* filename, const int id);

int init_sg_SpinerDependsRhoSie(const int matid, EOS* eos,
                                const char* filename, const int id);
#endif

int get_sg_eos(// sizing information
               int nmat, int ncell, int cell_dim,
               // Input parameters
               int input_int,
               // eos index offsets
               int* eos_offsets,
               // equation of state array
               EOS* eos,
               // index offsets
               int* offsets,
               // per cell quantities
               double* press, double* pmax, double* vol, double* spvol,
               double* sie, double* temp, double* bmod, double* dpde,
               double* cv,
               // per material quantities
               double* frac_mass, double* frac_vol, double* frac_sie,
               // optional per material quantities
               double* frac_bmod, double* frac_dpde, double* frac_cv);

int finalize_sg_eos(const int nmat, EOS* &eos, const int own_kokkos=0);

#if defined(__cplusplus)
}
#endif

#endif // EOS_SINGULARITY_EOS_HPP_
