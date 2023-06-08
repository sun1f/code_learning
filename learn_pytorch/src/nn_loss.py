import torch
from torch import nn

input = torch.tensor([1, 2, 3], dtype=torch.float32)
target = torch.tensor([1, 2, 5], dtype=torch.float32)

# input = torch.reshape(input, (1, 1, 1, 3))
# target = torch.reshape(target, (1, 1, 1, 3))

loss1 = nn.L1Loss(reduction='sum')
loss2 = nn.L1Loss(reduction='mean')

loss_mse = nn.MSELoss()

res1 = loss1(input, target)
res2 = loss2(input, target)
res_mse = loss_mse(input, target)

print(res1, res2, res_mse)