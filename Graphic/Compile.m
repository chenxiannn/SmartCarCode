clc;
clear mex
mex -I"../ControlLib/Inc" ...,
    imCar.c ...,
    imProc.c ...,
    imCom.c ...,
    ../ControlLib/ControlParam.c
CarSpeed=200;%单位为cm/s
CAMERA_W=160;
CAMERA_H=120;
for i=1:1000
    try
        imfilename=strcat('.\Image_bmp\fire',int2str(i),'.bmp');%输入图片
        svfilename=strcat('.\Image_bmp\solve\fire',int2str(i),'.bmp');%输出图片
        img=uint8(not(imread(imfilename))*255)';%加载BMP格式图片
        %img=uint8(load(imfilename))';      %加载txt文本格式图片
        [W H]=size(img);
        if W ~=CAMERA_W && H~= CAMERA_H
            continue
        end
        [L R M  dir imOut M_F M_Real]=imCar(img,CarSpeed);
        imshow(imOut) 
        hold on
        plot(1:1:CAMERA_H,[L R M],'-r')
        saveas(gcf,svfilename)
        close all
        clear mex
    catch e
        e
        continue
    end
end

