/** @class  FNMeteoClient FNMeteoClient.h
 *  @brief  Singleton Class for query all APIs
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Singleton Class for query all APIs. Just call it. (i.e.  `[[FNMeteoClient sharedInstance]getTimeSeriesByRegion`....)
 *  @date   July 2013
 */

#import "FNDefines.h"

/**
	The success block
 */
typedef void (^FNMeteoSuccess) (FNMeteoRequestOperation *operation, FNFeedBase *response);

/**
	The failure block
 */
typedef void (^FNMeteoFailure) (FNMeteoRequestOperation *operation, NSError *error);


@interface FNMeteoClient : NSObject

/**
 Set authentication for requests
 @param appID Application Identifier
 @param clientKey Client Key
 */
+(void) setApplicationId:(NSString *)appID clientKey:(NSString *)clientKey UNAVAILABLE_ATTRIBUTE;

/**
 Traslate FNMeteoModel enumerator to NSString for customized model output
 @param model enumerator
 @returns string correspong to the model
 */
+ (NSString *)modelEnumToString:(FNMeteoModel )model;

/**
 Singleton implementation always use like this: [[FNMeteoClient sharedInstance] methodName...
 @returns new istance
 */
+(id)sharedInstance;


/**
 Return all type of available models.
 */
-(void)getAllModelsWithBlockSuccess:(FNMeteoSuccess)success
                            failure:(FNMeteoFailure)failure;

/**
 Return all places.
 @param success block
 @param failure block
 */
-(void)getPlacesWithBlockSuccess:(FNMeteoSuccess)success
                         failure:(FNMeteoFailure)failure UNAVAILABLE_ATTRIBUTE;

/**
 Find place from its name
 @param placename place name like napoli, roma, or paris
 @param success   success block
 @param failure   failure block
 */
-(void)getPlaceByName:(NSString *)placename
         blockSuccess:(FNMeteoSuccess)success
              failure:(FNMeteoFailure)failure;

/**
 Find place from its identifier

 @param identifier string identifier like prov063 or prov65
 @param success   success block
 @param failure   failure block
 
 */
-(void)getPlaceByIdentifier:(NSString *)identifier
               blockSuccess:(FNMeteoSuccess)success
                    failure:(FNMeteoFailure)failure;

/**
 Get nearest places from location in rounded radius (default 5 KM)
 
 @param location your location coordinates
 @param radius   radius in KM, if 0 radius is 5
 @param success  success block
 @param failure  failure block
 */
-(void)getNearestPlacesFromLocation:(CLLocationCoordinate2D)location
                           inRadius:(NSInteger)radius
                       blockSuccess:(FNMeteoSuccess)success
                            failure:(FNMeteoFailure)failure;


/**
 Given a Region return weather info of current time. Model and Output default params are: 144h low resolution weather (wrf3), general view (gen)
 @param region the place you want informations
 @param success block
 @param failure block
 */
-(void)getWeatherForecastForNowPlace:(FNPlace *)region
                             success:(FNMeteoSuccess)success
                             failure:(FNMeteoFailure)failure;



/**
 Given a Region, Model, output type and custom time return weather info.You can obtain all models by Get Models API. You can obtain all output type by Get Output type from models API. If output is 'xml', the api return mean value of current time.
 @param DateTime current or past/future date
 @param model forecast you want
 @param region the place
 @param output kind of output
 @param success block
 @param failure block
 */
-(void)getWeatherForecastForDate:(NSDate *)DateTime
                           model:(FNMeteoModel )model
                           place:(FNPlace *)region
                          output:(NSString *)output
                         success:(FNMeteoSuccess)success
                         failure:(FNMeteoFailure)failure;

/**
 Given a Region, Model and output type return weather info of current time.You can obtain all models by Get Models API. You can obtain all output type by Get Output type from models API. If output is 'xml', the api return mean value of current time.
 @param model forecast you want
 @param region the place
 @param output kind of output
 @param success block
 @param failure block
 */
-(void)getWeatherForecastForNowPlace:(FNPlace *)region
                               model:(FNMeteoModel )model
                              output:(NSString *)output
                             success:(FNMeteoSuccess)success
                             failure:(FNMeteoFailure)failure;

/**
 Given a Region and Model return weather info of current time. Output default params is: general view (gen). You can obtain all models by Get Models API.
 @param model forecast you want
 @param region the place
 @param success block
 @param failure block
 */
-(void)getWeatherForecastForNowPlace:(FNPlace *)region
                               model:(FNMeteoModel )model
                             success:(FNMeteoSuccess)success
                             failure:(FNMeteoFailure)failure;

/**
 Given a model return all type of available outputs.
 @param model forecast you want
 @param success block
 @param failure block
 */
-(void)getOutputsfromModel:(FNMeteoModel )model
                   success:(FNMeteoSuccess)success
                   failure:(FNMeteoFailure)failure;
/**
 Given a Region return time series, start to current time.
 @param region the place
 @param success block
 @param failure block
 */
-(void)getTimeSeriesByRegion:(FNPlace *)region
                     success:(FNMeteoSuccess)success
                     failure:(FNMeteoFailure)failure;

/**
 Given a Region return time series, start to current time.
 @param model forecast you want
 @param region the place
 @param output kind of output
 @param success block
 @param failure block
 */
-(void)getTimeSeriesByRegion:(FNPlace *)region
                       model:(FNMeteoModel )model
                      output:(NSString *)output
                     success:(FNMeteoSuccess)success
                     failure:(FNMeteoFailure)failure;


@end
