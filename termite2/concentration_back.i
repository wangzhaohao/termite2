[Mesh]
    [block]
        type = GeneratedMeshGenerator
        dim = 2
        nx = 200
    []
[]

[Variables]
  [concentration]
    initial_condition = 1.6
  []
[]

[AuxVariables]
  [temp]
    order = SECOND
    family = MONOMIAL
  []
[]

[Kernels]
active = 'concentration_diff concentration_convection concentration_convection_temp concentration_diffusion_temp'
  [concentration_diff]
    type = Diffusion
    variable = concentration
  []
  [concentration_convection]
    type = ConcentrationConvection
    variable = concentration
    temp = temp
  []
  [concentration_convection_temp]
    type = ConcentrationConvectionTemp
    variable = concentration
    temp = temp
  []
  [concentration_diffusion_temp]
    type = ConcentrationDiffusionTemp
    variable = concentration
    temp = temp
  []
[]

[AuxKernels]
  [temp_parsed]
    type = ParsedAux
    use_xyzt = true
    function = 1
#    function = '-1500*x*x + 2000'
    variable = temp
  []
[]

[BCs]
  [right]
    type = DirichletBC
    variable = concentration
    boundary = right
    value = 1.6
  []
  [left]
    type = NeumannBC
    variable = concentration
    boundary = left
    value = 0
  []
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
[]

[Outputs]
  exodus = true
[]
