using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CM26dG.SDK.Models
{
    public class MeasurementResult
    {
        public double[] SpectrumSCI { get; set; }
        public double[] SpectrumSCE { get; set; }
        public double Gloss { get; set; }

        public (double L, double A, double B) LabSCI { get; set; }
        public (double L, double A, double B) LabSCE { get; set; }
    }



}

