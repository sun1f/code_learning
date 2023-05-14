from torch import nn
from torch.nn import ReLU, Sigmoid
import torchvision
from torch.utils.data import DataLoader
from torch.utils.tensorboard import SummaryWriter

dataset = torchvision.datasets.CIFAR10("Dataset2", train=False, transform=torchvision.transforms.ToTensor(), download=True)
dataloader = DataLoader(dataset, batch_size=64)

class ELL(nn.Module):
    def __init__(self):
        super(ELL, self).__init__()
        self.relu = ReLU()
        self.sigmoid = Sigmoid()

    def forward(self, input):
        output = self.sigmoid(input)
        return output

ell = ELL()

writer = SummaryWriter("logs")

step = 0
for data in dataloader:
    imgs, targets = data
    writer.add_images("input", imgs, global_step=step)
    output = ell(imgs)
    writer.add_images("output", output, global_step=step)
    step = step + 1

writer.close()