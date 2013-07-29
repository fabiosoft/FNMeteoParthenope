#import "FNFeedBase.h"
#import "FNPlace.h"
#import "FNMeteoForecast.h"
#import "FNObjDetail.h"
#import "FNForecastDetail.h"
#import "FNParthenopeClient.h"
#import <Networking/AFNetworking.h>
#import <Networking/FNCache.h>
#import "NSString+MD5.h"
#import "FNMeteoRequestOperation.h"
#import "NSObject+AutoDescription.h"

/**
 * Standard Models id enumeration
 */
typedef enum{
    // Meteo alta risoluzione 24h
    HIGH_RES_WEATHER_24H_WRF5 = 0,
    // Qualita' dell'aria bassa risoluzione 120h
    LOW_RES_AIR_QUALITY_120H_CHM3 = 1,
    // Vento altissima risoluzione 24h
    HIGHEST_RES_WIND_24H_CLM3 = 2,
    // Diffusione e trasporto inquinanti 120h
    POLLUTION_SPREAD_120H_LPD3 = 3,
    // Radar meteo (realtime)
    WEATHER_RADAR_LIVE_RDR1 = 4,
    // Dinamica costiera 120h
    COAST_DYNAMIC_120H_RMS3 = 5,
    // Meteo bassa risoluzione 144h
    LOW_RES_WEATHER_144H_WRF3 = 6,
    // Moto ondoso bassa risoluzione 144h
    WAVES_144H_WW33 = 7
    
} FNMeteoModel;


//DEFINES
#define IS_IPHONE ( [[[UIDevice currentDevice] model] isEqualToString:@"iPhone"] ||[[[UIDevice currentDevice] model] isEqualToString:@"iPhone Simulator"])
#define IS_IPOD   ( [[[UIDevice currentDevice ] model] isEqualToString:@"iPod touch"] )
#define IS_HEIGHT_GTE_568 [[UIScreen mainScreen ] bounds].size.height >= 568.0f
#define IS_IPHONE_5 ( IS_IPHONE && IS_HEIGHT_GTE_568 )
#define IOS_OLDER_THAN_6 ( [ [ [ UIDevice currentDevice ] systemVersion ] floatValue ] < 6.0 )
#define IOS_NEWER_OR_EQUAL_TO_6 ( [ [ [ UIDevice currentDevice ] systemVersion ] floatValue ] >= 6.0 )

#define IS_PORTRAIT [UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationPortrait || [UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationPortraitUpsideDown

#define IS_LANDASCAPE [UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationLandscapeLeft || [UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationLandscapeRight

#define showActivityIndicator [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:YES];
#define hideActivityIndicator [[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:NO];