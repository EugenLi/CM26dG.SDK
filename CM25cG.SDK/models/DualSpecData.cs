using Konicaminolta;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CM25cG.SDK.models
{
    public class DualSpecData
    {
        public SpecData SCI_Spec { get; set; }
        public SpecData SCE_Spec { get; set; }

        public (double L, double A, double B) LabSCI { get; set; }
        public (double L, double A, double B) LabSCE { get; set; }
    }
}
