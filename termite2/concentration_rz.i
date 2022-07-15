[Mesh]
    [block]
        type = GeneratedMeshGenerator
        dim = 2
        nx = 10
    []
[]

[Problem]
  type = FEProblem
  coord_type = RZ
  rz_coord_axis = Y
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
  [concentration_diff]
    type = Diffusion
    variable = concentration
  []
  [concentration_convection_source]
    type = ConcentrationConvectionSource
    variable = concentration
    temp = temp
  []
[]

[AuxKernels]
  [temp_parsed]
    type = ParsedAux
    use_xyzt = true
    function = '-1500*x*x + 2000'
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
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
[]

[Outputs]
  exodus = true
[]
