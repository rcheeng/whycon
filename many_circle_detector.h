#ifndef __CIRCLE_LOCALIZER_H__
#define __CIRCLE_LOCALIZER_H__

#include <vector>
#include "circle_detector.h"

namespace cv {
  class ManyCircleDetector {
    public:
      ManyCircleDetector(int number_of_circles, int width, int height, float diameter_ratio = WHYCON_DEFAULT_DIAMETER_RATIO);
      ~ManyCircleDetector(void);
      
      bool initialize(const cv::Mat& image);
      bool detect(const cv::Mat& image, int refine_max_step = 1);
      
      std::vector<CircleDetector::Circle> circles;

      CircleDetector::Context context;
      
    private:
      int width, height, number_of_circles;
      std::vector<CircleDetector> detectors;
  };
}

#endif
