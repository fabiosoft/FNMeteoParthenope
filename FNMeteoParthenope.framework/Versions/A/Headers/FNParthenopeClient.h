/** @class  FNParthenopeClient FNParthenopeClient.h
 *  @brief  Singleton Class for query all APIs
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Singleton Class for query all APIs. Just call it. (i.e.  `[[FNMeteoClient sharedInstance]getTimeSeriesByRegion`....)
 *  @date   July 2013
 */

#import <Networking/AFNetworking.h>
@interface FNParthenopeClient : AFHTTPClient

/**
 Singleton implementation always use like this: `[[FNMeteoClient sharedInstance] methodName...` use only for subclass
 @returns new istance
 */
+(id)sharedInstance;


@end
