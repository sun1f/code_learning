import torch
import torchvision
from torch import nn
from torch.nn import Linear
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter

dataset = torchvision.datasets.CIFAR10("../Dataset2", train=False, transform=torchvision.transforms.ToTensor(), download=True)

dataloader = DataLoader(dataset, batch_size=64, shuffle=True, drop_last=True)


class ELL(nn.Module):
    def __init__(self):
        super(ELL, self).__init__()
        self.linear = Linear(196608, 10)

    def forward(self, input):
        output = self.linear(input)
        return output

ell = ELL()
writer = SummaryWriter("../logs")

for data in dataloader:
    imgs, target = data
    print(imgs.shape)
    # output = torch.reshape(imgs, (1, 1, 1, -1))
    output = torch.flatten(imgs)
    print(output.shape)
    output = ell(output)
    print(output.shape)