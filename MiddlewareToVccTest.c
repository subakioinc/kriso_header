#include <stdio.h>
#include <string.h>

#include <stdint.h>

typedef struct _NaviInfo {
    uint8_t nav_mode; //항법모드 (single/RTK/INS)
    float nav_roll; //degree roll
    float nav_pitch; //degree pitch
    float nav_yaw; //degree yaw
    float nav_cog; //degree COG
    float nav_sog; //knots degree SOG
    float nav_uspd; //konts longitudinal speed
    float nav_vspd; //knots traversal speed
    float nav_wspd; //knots vertical speed
    double nav_longitude; //degree 경도
    double nav_latitude; //degree 위도
    float nav_heave; //m Heave
    float nav_gpstime; // hhmmss.s GPS시간
} NaviInfo;



typedef struct _WeatherInfo {
    float wea_airtem; //degree 공기 온도
    float wea_wattem; //degree 해수 온도
    float wea_press;  //bar 기압
    float wea_relhum; //% 상대습도
    float wea_dewpt;  //degree 이슬점
    float wea_windirt; //degree 풍향(절대)
    float wea_winspdt; //knots 풍속(절대)
    float wea_windirr;  //degree 풍향(상대)
    float wea_watspdr;  //knots 풍속(상대)
    float wea_watdir;   //degree 유향
    float wea_watspd;  //knots 유속
    float wea_visibiran; //m 가시거리
} WeatherInfo;

typedef struct _MiddlewareToVcc {
    NaviInfo navInfo;
    WeatherInfo weatherinfo;
} MiddlewareToVcc;

/*
//from kriso integrated struct
typedef struct _MiddlewareToVccNaviInfo {
    uint8_t nav_mode; //항법모드 (single/RTK/INS)
    float nav_roll; //degree roll
    float nav_pitch; //degree pitch
    float nav_yaw; //degree yaw
    float nav_cog; //degree COG
    float nav_sog; //knots degree SOG
    float nav_uspd; //konts longitudinal speed
    float nav_vspd; //knots traversal speed
    float nav_wspd; //knots vertical speed
    double nav_longitude; //degree 경도
    double nav_latitude; //degree 위도
    float nav_heave; //m Heave
    float nav_gpstime; // hhmmss.s GPS시간
    float wea_airtem; //degree 공기 온도
    float wea_wattem; //degree 해수 온도
    float wea_press;  //bar 기압
    float wea_relhum  //% 상대습도
    float wea_dewpt;  //degree 이슬점
    float wea_windirt //degree 풍향(절대)
    float wea_winspdt; //knots 풍속(절대)
    float wea_windirr;  //degree 풍향(상대)
    float wea_watspdr;  //knots 풍속(상대)
    float wea_watdir;   //degree 유향
    float wea_watspd;  //knots 유속
    float wea_visibiran; //m 가시거리
} MiddlewareToVccNaviInfo;
*/

void main(){
    MiddlewareToVcc mv;
    memset(&mv, 0, sizeof(MiddlewareToVcc) );
    mv.navInfo.nav_mode = 0.01;
    mv.navInfo.nav_gpstime = 0.02;
    mv.weatherinfo.wea_airtem = 0.1;
    mv.weatherinfo.wea_visibiran = 0.2;
    
    MiddlewareToVcc mv2;
    memset(&mv2, 0, sizeof(MiddlewareToVcc) );
    
    memcpy(&mv2, &mv, sizeof(MiddlewareToVcc));

    printf("%f %f",mv2.navInfo.nav_gpstime, mv.navInfo.nav_gpstime);
}
