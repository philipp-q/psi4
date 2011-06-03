#include <stdio.h>
#include <libint/libint.h>
#include "libderiv.h"
#include <libint/vrr_header.h>
#include <libint/hrr_header.h>
#include "deriv_header.h"

  /* Computes quartets necessary to compute derivatives of (00|p0) integrals */

void d1vrr_order_00p0(Libderiv_t *Libderiv, prim_data *Data)
{
 double *dvrr_stack = Libderiv->dvrr_stack;
 double *tmp, *target_ptr;
 int i, am[2];
 /* compute (0 0 | 1 0) m=0 deriv level 0 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  0 0 0 */
 _BUILD_00p0(Data,dvrr_stack+0, Data->F+0, Data->F+1, NULL, NULL, NULL);

 /* compute (0 0 | 1 0) m=1 deriv level 0 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  0 0 0 */
 _BUILD_00p0(Data,dvrr_stack+3, Data->F+1, Data->F+2, NULL, NULL, NULL);

 /* compute (0 0 | 2 0) m=0 deriv level 0 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  0 0 0 */
 _BUILD_00d0(Data,dvrr_stack+6, dvrr_stack+0, dvrr_stack+3, Data->F+0, Data->F+1, NULL);

 /* compute (0 0 | 1 1) m=0 deriv level 0 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  0 0 0 */
 hrr3_build_pp(Libderiv->CD,dvrr_stack+12,dvrr_stack+6,dvrr_stack+0,1);


 /* compute (1 0 | 1 0) m=0 deriv level 0 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  0 0 0 */
 _BUILD_p0p0(Data,dvrr_stack+21, dvrr_stack+0, dvrr_stack+3, NULL, NULL, Data->F+1);

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  0 0 1 */
 deriv_build_DZ_0(Data,3,dvrr_stack+0, dvrr_stack+12, NULL);
 tmp = dvrr_stack + 0;
 target_ptr = Libderiv->deriv_classes[0][1][11];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  0 1 0 */
 deriv_build_DY_0(Data,3,dvrr_stack+3, dvrr_stack+12, NULL);
 tmp = dvrr_stack + 3;
 target_ptr = Libderiv->deriv_classes[0][1][10];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 0  1 0 0 */
 deriv_build_DX_0(Data,3,dvrr_stack+30, dvrr_stack+12, NULL);
 tmp = dvrr_stack + 30;
 target_ptr = Libderiv->deriv_classes[0][1][9];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 0 0  0 0 0  0 0 1  0 0 0 */
 deriv_build_CZ_p(Data,1,1,dvrr_stack+12, dvrr_stack+6, Data->F+0);
 tmp = dvrr_stack + 12;
 target_ptr = Libderiv->deriv_classes[0][1][8];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 0 0  0 0 0  0 1 0  0 0 0 */
 deriv_build_CY_p(Data,1,1,dvrr_stack+15, dvrr_stack+6, Data->F+0);
 tmp = dvrr_stack + 15;
 target_ptr = Libderiv->deriv_classes[0][1][7];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 0 0  0 0 0  1 0 0  0 0 0 */
 deriv_build_CX_p(Data,1,1,dvrr_stack+18, dvrr_stack+6, Data->F+0);
 tmp = dvrr_stack + 18;
 target_ptr = Libderiv->deriv_classes[0][1][6];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 0 1  0 0 0  0 0 0  0 0 0 */
 deriv_build_AZ_0(Data,3,dvrr_stack+6, dvrr_stack+21, NULL);
 tmp = dvrr_stack + 6;
 target_ptr = Libderiv->deriv_classes[0][1][2];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 0 1 0  0 0 0  0 0 0  0 0 0 */
 deriv_build_AY_0(Data,3,dvrr_stack+9, dvrr_stack+21, NULL);
 tmp = dvrr_stack + 9;
 target_ptr = Libderiv->deriv_classes[0][1][1];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];

 /* compute (0 0 | 1 0) m=0 deriv level 1 */
 /* deriv_ind: 1 0 0  0 0 0  0 0 0  0 0 0 */
 deriv_build_AX_0(Data,3,dvrr_stack+33, dvrr_stack+21, NULL);
 tmp = dvrr_stack + 33;
 target_ptr = Libderiv->deriv_classes[0][1][0];
 for(i=0;i<3;i++)
   target_ptr[i] += tmp[i];


}
