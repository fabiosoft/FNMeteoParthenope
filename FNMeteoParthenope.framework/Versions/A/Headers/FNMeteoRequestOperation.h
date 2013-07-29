/** @class  FNMeteoRequestOperation FNMeteoRequestOperation.h
 *  @brief  Network operation class
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Network operation class. With feed or error always returns information about network connection
 *  @date   July 2013
 */

#import <Foundation/Foundation.h>
#import "FNDefines.h"
@interface FNMeteoRequestOperation : AFJSONRequestOperation

/**
	Generate MD5 hashed string object operation for url remote path. You can use this for caching request or save it for later.
	@param urlPath URL remote service
	@returns hasched operation string
 */
+(NSString *)reqStringFrom:(NSString *)urlPath;


@end
