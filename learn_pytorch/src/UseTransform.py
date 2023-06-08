from PIL import Image
from torch.utils.tensorboard import SummaryWriter
from torchvision import transforms

writer = SummaryWriter("../logs")
img = Image.open("../image/messi.jpg")
print(img)

# ToTensor
trans_tensor = transforms.ToTensor()
img_tensor = trans_tensor(img)
writer.add_image("ToTensor", img_tensor)

# Normalize
print(img_tensor[0][0][0])
trans_norm = transforms.Normalize([0.5, 0.5, 0.5], [0.5, 0.5, 0.5])
img_norm = trans_norm(img_tensor)
print(img_norm[0][0][0])
writer.add_image("Normalize", img_norm, 2)

# Resize
print(img.size)
trans_resize = transforms.Resize((512, 512))
# img PIL -> resize -> img_resize PIL
img_resize = trans_resize(img)
# img_resize -> totensor -> img_resize tensor
img_resize = trans_tensor(img_resize)
writer.add_image("Resize", img_resize, 0)
print(img_resize)

# Compose - resize 2
trans_resize_2 = transforms.Resize(512)
trans_compose = transforms.Compose([trans_resize_2, trans_tensor])
img_resize_2 = trans_compose(img)
writer.add_image("Resize", img_resize_2, 1)

# Random Crop
random_crop = transforms.RandomCrop((500, 1000))
trans_random_compose = transforms.Compose([random_crop, trans_tensor])
for i in range(10):
    img_random_crop = trans_random_compose(img)
    writer.add_image("RandomCompose", img_random_crop, i)

writer.close()
