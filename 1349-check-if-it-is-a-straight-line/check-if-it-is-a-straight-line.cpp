class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       double slope1;
       double slope2;

        double x1 = coordinates[0][0];
        double y1 = coordinates[0][1];
        double x2 = coordinates[1][0];
        double y2 = coordinates[1][1];
        //slope1 = (y2-y1)/(x2-x1);

        
        //if((x2-x1) == 0) {return false;}


      for(int i = 2; i< coordinates.size(); i++){
       
      double x = coordinates[i][0];
      double y = coordinates[i][1];

      //if((x-x1) == 0) {return false;}


      
      //slope2 = (y-y1)/(x-x1);        

      if ( ((y2-y1)*(x-x1) != ((y-y1)*(x2-x1)))) {
        return false;
      }
        //else if((x-x1) == 0 && slope1 == slope2) return true;

       }

        return true;
    }
};