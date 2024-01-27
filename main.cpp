#include <iostream>
#include <string>
#include<cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
const int size = 256;
unsigned char image[size][size];
unsigned char image2[size][size];
unsigned char newimage[size][size];
void loadimage();
//__________________________
void loadimage2();
//__________________________
void saveimage();
//__________________________
void savenewimage();
//__________________________
void darken_and_LightenImage();
//__________________________
void mergephotos();
//__________________________
void invertimage();
//__________________________
void rotateimage ();
//__________________________
void flipimage();
//__________________________
void blackwhiteImage();
//__________________________
void blurimage();
//__________________________
void shrinkimage();
//__________________________
void enlargeimage();
//__________________________
void mirror();
//__________________________
void shuffleimage();
//__________________________;
void detectedges();
//__________________________
int main () {
    int x;
    cout << "Ahlan ya user ya habibi" << endl << "Please enter file name of the image to load:";
    loadimage();
    while (true) {
        cout << "Please select a filter's number to apply or 0 to exit: \n"

                "1-Rotate Filter\n"
                "2-Merge Filter\n"
                "3-Darken and Lighten Image\n"
                "4-Invert Image\n"
                "5-Flip Image\n"
                "6-Black and White Filter\n"
                "7-Shrink Image\n"
                "8-Blur Image\n"
                "9-Enlarge Image\n"
                "10-Mirror 1/2 Image\n"
                "11-Shuffle Image\n"
                "12-Detect Image Edges\n"
                "0-Exit\n";
        cin >> x;
        if (x == 1) {
            rotateimage();
            savenewimage();

        } else if (x == 2) {
            loadimage2();
            mergephotos();
            savenewimage();

        } else if (x == 3) {
            darken_and_LightenImage();
            savenewimage();

        } else if (x == 4) {
            invertimage();
            saveimage();

        } else if (x == 5) {
            flipimage();
            savenewimage();

        } else if (x == 6) {
            blackwhiteImage();
            saveimage();

        } else if (x == 7) {
            shrinkimage();
            savenewimage();

        } else if (x == 8) {
            blurimage();
            savenewimage();

        } else if (x == 9) {
            enlargeimage();
            savenewimage();

        } else if (x == 10) {

            mirror();
            savenewimage();

        } else if (x == 11) {

            shuffleimage();
            savenewimage();

        } else if (x == 12) {

            detectedges();
            savenewimage();

        } else if (x == 0) {
            return 0;
        }
    }
}
void loadimage(){
    char image_file_name[100];
    cin>>image_file_name;
    strcat(image_file_name, ".bmp");
    readGSBMP(image_file_name, image);
}
void loadimage2(){
    char image_file_name_2[100];
    cout << "please enter image2's name: ";
    cin>>image_file_name_2;
    strcat(image_file_name_2, ".bmp");
    readGSBMP(image_file_name_2, image2);
}
void saveimage(){
    char image_file_name[100];
    cout << "Please enter the image file name to save:  ";
    cin >> image_file_name;
    strcat(image_file_name,".bmp");
    writeGSBMP(image_file_name, image);
}
void savenewimage(){
    char image_file_name[100];
    cout << "Please enter the image file name to save:  ";
    cin >> image_file_name;
    strcat(image_file_name,".bmp");
    writeGSBMP(image_file_name, newimage);
}
void mergephotos(){// To merge two photos.
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            newimage[i][j] = (image[i][j] + image2[i][j])/2;
        }
    }
}
void darken_and_LightenImage()
{
    char m;
    cout << "Do you want to (d)arken or (l)ighten? ";
    cin >> m;
    if(m=='d')
    {//To lighten the image
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                newimage[i][j] = (image[i][j])/2;
            }
        }
    }else if(m=='l')
    {//To darken the image
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                newimage[i][j] = ((image[i][j])+255)/2;
            }
        }
    }
}
void rotateimage () {
    int degree;
    cout << "Rotate (90), (180) or (270) degrees? ";
    cin >> degree;
    if (degree == 90)
    {
        for (int i = 0; i < size; ++i) {//ROTATE 90
        for (int j = 0; j < size; ++j) {
            newimage[i][j] = image[255 - j][i];
        }
        }
    }else if (degree == 180)
    {
        for (int i = 0; i < size; ++i) {//ROTATE 180
            for (int j = 0; j < size; ++j) {
                newimage[i][j]=image[size-i][size-j];
            }
        }
    }else
    {
        for (int i = 0; i < size; ++i) { //ROTATE 270
            for (int j = 0; j < size; ++j) {
                newimage[i][j] = image[j][size-i];
            }
        }
    }
}
void flipimage() {
    int pixel = 255;
    char flip;
    cout << "Flip (h)orizontally or (v)ertically? ";
    cin >> flip;
    if (flip == 'v'){
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                newimage [i][j] = image [i][j+pixel];
                ----pixel;
            }

        }
    }else
    {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                newimage[i][j] = image[i+pixel][j];
            }
            pixel--;
            pixel--;
        }
    }
}

void blackwhiteImage() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}
void invertimage(){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            image[i][j] = abs(image[i][j]-255);
        }
    }
}
void shrinkimage(){
    int l = 0 , m = 0;
    double x = 0.5 ,z = 0.3 ;
    double n;
    cout << "Shrink to (0.5), (0.3) or (0.25) ? ";
    cin >>n ;
    if (n == x)
    {//Shrinking 1/2 the image
        for (int i = 0; i < size; i += 2) {
            for (int j = 0; j < size; j += 2) {
                newimage[l][m] = image[i][j];
                m++ ;
            }
            m = 0;
            l++ ;
        }
    }else if (n == z)
    {//Shrinking 1/3 the image
        for (int i = 0; i < size; i += 3) {
            for (int j = 0; j < size; j += 3) {
                newimage[l][m] = image[i][j];
                m++ ;
            }
            m = 0;
            l++ ;
        }
    }else
    {//Shrinking 1/4 the image
        for (int i = 0; i < size; i += 4) {
            for (int j = 0; j < size; j += 4) {
                newimage[l][m] = image[i][j];
                m++ ;
            }
            m = 0;
            l++ ;
        }
    }
}
void blurimage() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {//Calculating the sum of the pixels and dividing it over the average to blur the image
            newimage[i][j] = ((image[i][j] + image[i][j+1] + image[i][j+2] + image[i+1][j] + image[i+1][j+1] +
                    image[i+1][j+2] + image[i+2][j] + image[i+2][j+1] + image[i+2][j+2]) / 9);
        }
    }
}
void enlargeimage(){
    for (int i = 0, k = 0; i < size; k += 1, i += 2) {
        for (int j = 0, l = 0 ; j < size; l += 1, j += 2) {
            newimage[i][j] = image[k][l];
            newimage[i][j+1] = image[k][l];
            newimage[i+1][j] = image[k][l];
            newimage[i+1][j+1] = image[k][l];
        }
    }
}

void mirror(){
    char side;

    cout << "Mirror (l)eft, (r)ight, (u)pper or (d)own side? ";
    cin >> side;
    if (side == 'l'){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < 128; ++j) {
                newimage[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < size ; ++i ){
            for (int j = 127, l = 128; j >= 0; --j, l++) {
                newimage[i][l] = newimage[i][j];
            }
        }
    }else if (side == 'r'){
        for (int i = 0; i < size; ++i) {
            for (int j = 128; j < size; ++j) {
                newimage[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < size ; ++i ){
            for (int j = 128, l = 127; j < size; ++j, --l) {
                newimage[i][l] = newimage[i][j];
            }
        }
    }else if (side == 'u'){
        for (int i = 0; i < 128; ++i) {
            for (int j = 0; j < size; ++j) {
                newimage[i][j] = image[i][j];
            }
        }
        for (int i = 127, k = 128; i >= 0 ; --i, k++) {
            for (int j = 0, l = 0; j < size; ++j, l++) {
                newimage[k][l] = newimage[i][j];
            }
        }
    }else{
        for (int i = 128; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                newimage[i][j] = image[i][j];
            }
        }
        for (int i = 128, k = 127; i < size ; ++i, k--) {
            for (int j = 0, l = 0; j < size; ++j, l++) {
                newimage[k][l] = newimage[i][j];
            }
        }
    }
}
void detectedges(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (image[i][j] > (size/2)+2)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    for (int i = 1; i < size; ++i) {
        for (int j = 1; j < size; ++j) {
            newimage[i][j] = ((image[i][j] + image[i][j+1] + image[i+1][j] + image[i-1][j] + image[i][j-1] + 4)
                    * image[i][j]);
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            newimage[i][j] = abs(newimage[i][j]-255);
        }
    }
}
void shuffleimage(){
    string choice;
    cout << "please enter the order of quads that you want to shuffle to EX : 4321 :- ";
    cin>>choice;
    if (choice.substr(0,1) == "1"){
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i][j] = image[i][j];

            }
        }
    }else if (choice.substr(0,1) == "2")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i][j] = image[i][j+127];

            }
        }
    }else if (choice.substr(0,1) == "3")
    {
        for (int i = 0 ; i < (SIZE/2)+1;i++){
            for (int j = 0;j < (SIZE/2)+1 ;j++){
                newimage[i][j] = image[i+127][j];

            }
        }
    }else if (choice.substr(0,1) == "4")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i][j] = image[i+127][j+127];

            }
        }
    }
    if (choice.substr(1,1) == "1")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i][j+127] = image[i][j];

            }
        }
    }else if (choice.substr(1,1) == "2")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i][j+127] = image[i][j+127];

            }
        }
    }else if (choice.substr(1,1) == "3")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i][j+127] = image[i+127][j];

            }
        }
    }else if (choice.substr(1,1) == "4")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i][j+127] = image[i+127][j+127];

            }
        }
    }
    if (choice.substr(2,1) == "1"){
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i+127][j] = image[i][j];

            }
        }
    }else if (choice.substr(2,1) == "2")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i+127][j] = image[i][j+127];

            }
        }
    }else if (choice.substr(2,1) == "3")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i+127][j] = image[i+127][j];

            }
        }
    }else if (choice.substr(2,1) == "4")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i+127][j] = image[i+127][j+127];

            }
        }
    }
    if (choice.substr(3,1) == "1")
    {
        for (int i = 0 ; i < (SIZE/2)+1;i++){
            for (int j = 0;j < (SIZE/2)+1 ;j++){
                newimage[i+127][j+127] = image[i][j];

            }
        }
    }else if (choice.substr(3,1) == "2")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i+127][j+127] = image[i][j+127];

            }
        }
    }else if (choice.substr(3,1) == "3")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i+127][j+127] = image[i+127][j];

            }
        }
    }else if (choice.substr(3,1) == "4")
    {
        for (int i = 0 ; i < (size/2)+1;i++){
            for (int j = 0;j < (size/2)+1 ;j++){
                newimage[i+127][j+127] = image[i+127][j+127];

            }
        }
    }
} 