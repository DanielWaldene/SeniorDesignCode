#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <fstream>
#include "yolo.hpp"
// Constants
using namespace std;
using namespace cv;



int main(){

    
    InferenceEngine yolo("../visdrone.onnx", {640,640}, "../VisDroneClasses.txt", false);
    VideoCapture cap("../video.mp4");
    dnn::getAvailableBackends();
    


    if(!cap.isOpened()){
        cout<< "error unable to open video"<<endl;
        return -1;
    }
    for(;;){
        Mat frame;
        cap >>frame;
        if(frame.empty()){
            cout << "error unable to read frame"<<endl;
            break;
        }
        namedWindow("yolo inference", WINDOW_AUTOSIZE);
        vector<Detection> results = yolo.runInference(frame);
        int detections = results.size();
        for(int i = 0; i < detections; i++){
            Detection detection = results[i];
            cv::Rect box = detection.box;
            cv::Scalar color = detection.color;
            cv::rectangle(frame, box, color, 2);
            std::string classString = detection.className+" "+std::to_string(detection.confidence).substr(0,4);
            Size textsize =getTextSize(classString, cv::FONT_HERSHEY_DUPLEX, 1, 2,0);
            Rect textbox(box.x, box.y-40, textsize.width+10,textsize.height+20);
            rectangle(frame, textbox, color, FILLED);
            putText(frame, classString,Point(box.x+5,box.y-10), FONT_HERSHEY_DUPLEX, 1, Scalar(0,0,0), 2,0);
        }
        float scale = 0.8;
        resize(frame, frame, Size(frame.cols*scale, frame.rows*scale));
        imshow("yolo inference", frame);
        if(waitKey(1) =='q'){
            break;
        }
    }
    destroyAllWindows();
    cap.release();
    
    return 0;
}
    