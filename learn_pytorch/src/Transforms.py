from torchvision import transforms
from PIL import Image
from torch.utils.tensorboard import SummaryWriter
import cv2

img_path = "../data/train/ants_image/6743948_2b8c096dda.jpg"
img = Image.open(img_path)
cv_img = cv2.imread(img_path, 1)
# opencv默认是BGR格式
cv_img = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
# print(type(cv_img)) 输出：<class 'numpy.ndarray'>
# print(img)
# img.show()

writer = SummaryWriter("../logs")

tensor_trans = transforms.ToTensor()  # 相当于从transform工具箱拿一个tool出来
tensor_img = tensor_trans(img)  # 参数必须是两种类型之一：pic (PIL Image or numpy.ndarray): Image to be converted to tensor.
# print(tensor_img)
tensor_img_cv = tensor_trans(cv_img)

writer.add_image("Tensor_img", tensor_img, 1)

writer.add_image("Tensor_img", tensor_img_cv, 2)

writer.close()
