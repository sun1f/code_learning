import torch
from torch import nn

class ELL(nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, input):
        output = input + 1
        return output

ell = ELL()
x = torch.tensor(1.0)
output = ell(x)
print(output)