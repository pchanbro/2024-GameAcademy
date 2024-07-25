﻿using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class PsyTblChampion
{
    public int Key { get; set; }

    public string? Name { get; set; }

    public virtual ICollection<PsyTblUser> PsyTblUsers { get; set; } = new List<PsyTblUser>();
}
