import torch
import torchvision
from torch.utils.data import DataLoader
from torch import nn
from torch.nn import Conv2d
from torch.utils.tensorboard import SummaryWriter

dataset = torchvision.datasets.CIFAR10("./Dataset2", train=False, transform=torchvision.transforms.ToTensor(), download=True)

dataloader = DataLoader(dataset, batch_size=64, shuffle=True, drop_last=False)

class ELL(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = Conv2d(in_channels=3, out_channels=6, kernel_size=3, stride=1, padding=0)

    def forward(self, x):
        x = self.conv1(x)
        return x

ell = ELL()
# print(ell)

writer = SummaryWriter("logs")

step = 0
for data in dataloader:
    imgs, targets = data
    output = ell(imgs)
    # torch.Size([64, 3, 32, 32])
    print(imgs.shape)
    # torch.Size([64, 6, 30, 30])
    print(output.shape)
    writer.add_images("input", imgs, step)
    writer.add_images("output", torch.reshape(output, (-1, 3, 30, 30)), step)

    step = step + 1

writer.close()