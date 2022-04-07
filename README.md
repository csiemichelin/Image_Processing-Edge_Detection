# Image_Processing-Edge_Detection
## 目錄
 - [Data_handed_in](#Data_handed_in)
 - [Technical_description](#Technical_description)
 - [Experimental_results](#Experimental_results)
## Data_handed_in  
**1. sobel_operator 資料夾**  
&emsp;sobel_operator.cpp    
&emsp;sobel_operator.exe    
&emsp;image1.jpg   
&emsp;image2.jpg   
&emsp;image3.jpg     
**2. laplacian_of_gaussian 資料夾**  
&emsp;laplacian_of_gaussian.cpp    
&emsp;laplacian_of_gaussian.exe    
&emsp;image1.jpg   
&emsp;image2.jpg   
&emsp;image3.jpg     
## Technical_description  
**1. sobel_operator**
&emsp;(1) 目的 : 是圖像處理中的算子之一，Sobel operator就是在對每一個像素求出梯度的近似值，主要用來做邊緣偵測。   
&emsp;(2) 公式 :   
&emsp;&emsp;以下兩種矩陣:   
&emsp;&emsp;gx是針對縱向的變化（找到的Edge是水平的）；gy則是橫向的變化（找到的Edge是垂直的）。    
&emsp;&emsp;將上述係數乘上矩陣中的gray level，得到Gx=(-1)*a1+(-2)*a2+(-1)*a3+(0)*a4+(0)*a5+(1)*a6+(2)*a7+(1)*a8，求出一個像素的Gx和Gy後，我們可以利用下面的式子，當作這個像素的梯度近似值：而最外圍的一圈像素，由於它們的周圍沒有八個點，我就直接把它們的輸出設成0了。最後再設立一個門檻，若G的值高於這個門檻，則把輸出中相對應的像素設成白色(像素值255)；否則設成黑色(像素值0)。   
**2. Laplacian of a Gaussian (LoG)**
&emsp;(1) 目的 : 拉普拉斯算子可以突出圖像中強度發生快速變化的區域，因此常用在邊緣檢測任務當中。在進行Laplacian操作之前通常需要先用高斯平滑濾波器對圖像進行平滑處理，以降低Laplacian操作對於噪聲的敏感性。  
&emsp;(2) 公式 :  
&emsp;&emsp;在此實驗中利用一個5 * 5的矩陣作為 mask，對像素做完運算以後，取絕對值，並檢查數值是否超過255，如果超過的話，數值為255。   
## Experimental_results
&emsp;(1) 前置作業 :   
&emsp;&emsp;(一) 作業系統 : Windows 10 家用版     
&emsp;&emsp;(二) Visual studio 版本 : Visual Studio 2019     
&emsp;&emsp;(三) OpenCV 版本 : OpenCV 4.5.3     
&emsp;&emsp;(四) 環境架設 :        
&emsp;&emsp;&emsp;https://forum.gamer.com.tw/C.php?bsn=60292&snA=6494   
&emsp;(2) Sobel operator (左:原圖，右:邊緣偵測後後的圖)    
&emsp;&emsp;(一) image1.jpg   
&emsp;&emsp;(二) image2.jpg   
&emsp;&emsp;(三) image3.jpg   
&emsp;(3) Laplacian of a Gaussian (LoG) (左:原圖，右:邊緣偵測後後的圖)   
&emsp;&emsp;(一) image1.jpg   
&emsp;&emsp;(二) image2.jpg   
&emsp;&emsp;(三) image3.jpg   
