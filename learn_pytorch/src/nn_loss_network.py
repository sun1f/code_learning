import torchvision
from torch import nn
from torch.nn import Sequential, MaxPool2d, Conv2d, Flatten, Linear
from torch.utils.data import DataLoader

dataset = torchvision.datasets.CIFAR10("../Dataset2", train=False, transform=torchvision.transforms.ToTensor(), download=True)
dataloader = DataLoader(dataset, batch_size=64)
class ELL(nn.Module):
    def __init__(self):
        super(ELL, self).__init__()
        self.module = Sequential(
            Conv2d(3, 32, 5, padding=2),
            MaxPool2d(2),
            Conv2d(32, 32, 5, padding=2),
            MaxPool2d(2),
            Conv2d(32, 64, 5, padding=2),
            MaxPool2d(2),
            Flatten(),
            Linear(1024, 64),
            Linear(64, 10)
        )

    def forward(self, input):
        return self.module(input)

loss = nn.CrossEntropyLoss()
ell = ELL()
for data in dataloader:
    imgs, targets = data
    outputs = ell(imgs)
    res_loss = loss(outputs, targets)
    res_loss.backward()
    print('ok')
