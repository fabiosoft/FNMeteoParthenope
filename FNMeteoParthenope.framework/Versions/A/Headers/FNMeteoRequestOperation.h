/** @class  FNMeteoRequestOperation FNMeteoRequestOperation.h
 *  @brief  Network operation class
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Network operation class. With feed or error always returns information about network connection
 *  @date   July 2013
 */

#import <Foundation/Foundation.h>
#import "FNDefines.h"
@interface FNMeteoRequestOperation : NSObject

/**
	Request sent
 */
@property (nonatomic,strong,readonly) NSURLRequest *theRequest;
/**
	Response received
 */
@property (nonatomic,strong,readonly) NSHTTPURLResponse *theResponse;


/**
	Generate MD5 hashed string object operation for url remote path. You can use this for caching request or save it for later.
	@param urlPath URL remote service
	@returns hasched operation string
 */
+(NSString *)reqStringFrom:(NSString *)urlPath;

/**
	Create a FNMeteoRequestOperation starting from the Request and the Response
	@param theRequest Request sent
	@param theResponse Response received
 */
-(id)initMeteoRequestOperationWithReq:(NSURLRequest *)theRequest theResponse:(NSHTTPURLResponse *)theResponse;


@end
