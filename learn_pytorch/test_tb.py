from torch.utils.tensorboard import SummaryWriter
from PIL import Image
import numpy as np

writer = SummaryWriter("logs")

image_path = "dataset/hymenoptera_data/train/bees/95238259_98470c5b10.jpg"
img_PIL = Image.open(image_path)
print(type(img_PIL))

img_array = np.array(img_PIL)
print(type(img_array))
print(img_array.shape)
writer.add_image("test", img_array, 2, dataformats='HWC')

# y = 2x
for i in range(100):
    writer.add_scalar("y = 2x", 2 * i, i)

writer.close()
