[Mesh]
  type = GeneratedMesh # Can generate simple lines, rectangles and rectangular prisms
  dim = 2 # Dimension of the mesh
  nx = 10 # Number of elements in the x direction
  ny = 10 # Number of elements in the y direction
[]

[Variables]
  [./whatever]
    #Adds a Linear Lagrange variable by default
  [../]
[]

[Kernels]
  [./whatever]
    type = LaplaceYoung # A Laplacian operator
    variable = whatever # Operate on the "pressure" variable from above
  [../]
[]

[BCs]
  [./inlet]
    type =  # Simple u=value BC
    variable = whatever 
    boundary = left # Name of a sideset in the mesh
    value = 4000 # (Pa) From Figure 2 from paper.  First data point for 1mm balls.
  [../]
  [./outlet]
    type = DirichletBC
    variable = whatever 
    boundary = right
    value = 0 # (Pa) Gives the correct pressure drop from Figure 2 for 1mm balls
  [../]
[]

[Executioner]
  type = Steady # Steady state problem
[]

[Outputs]
  exodus = true # Output Exodus format
[]
