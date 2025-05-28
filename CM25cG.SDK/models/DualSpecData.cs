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
        public SpecData SCI { get; set; }
        public SpecData SCE { get; set; }
    }
}
