/** @class  FNFeedBase FNFeedBase.h
 *  @brief  Class box, can contains ather classes entries
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Class box, can contains ather classes entries. Usally some FNMeteoClient methods return this kind of feed
 *  @date   July 2013
 */


#import <Foundation/Foundation.h>

@interface FNFeedBase : NSObject <NSCoding>

/**
 Feed MD5, calculate remotely
 */
@property (nonatomic,readonly,strong) NSString *md5Feed;

/**
 Mutable array contains all retrieved data
 */
@property (nonatomic, strong) NSMutableArray *entries;


/**
 Initialize a new feed from an usual server response
 @param response a dictionary with keys structure: "infoplace" -> "places" -> "md5"
 @warning response is mandatory
 @returns new FNFeedBase
 */
-(id)initWithFeedResponse:(NSDictionary *)response;

/**
 Initialize a new feed from a timeseries
 @warning response is mandatory
 @param response  a dictionary with timeseries keys structure
 @returns new FNFeedBase
 */
-(id)initWithTimeSeries:(NSDictionary *)response;

/**
 Just initialize it with default data
 @returns new FNFeedBase
 */
-(id)init;



@end
