/** @class  FNPlace FNPlace.h
 *  @brief  Class object, rapresenting a region or a country
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Class object, rapresenting a region or a country, you need to initialize a new object for make and retrieve weather information about a place.
 *  @date   July 2013
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "FNDefines.h"
#import "NSObject+AutoCoding.h"

@interface FNPlace : NSObject  <NSCoding>


/**
 Place identifier, usally the region code
 */
@property (nonatomic,readonly,strong) NSString *identifier;

/**
 Left points bounding box (bb) is summarized like "longLeft latLeft longRight latRight" example: "13.97 40.87 14.07 40.95"
 */
@property (nonatomic,strong) CLLocation *leftBoundingBoxCoords;

/**
 Right points bounding box (bb) is summarized like "longLeft latLeft longRight latRight" example: "13.97 40.87 14.07 40.95"
 */
@property (nonatomic,strong) CLLocation *rightBoundingBoxCoords;

/**
 Center is summarized like "long lat" example: "14.02 40.91"
 */
@property (nonatomic,strong) CLLocation *centerCoords;

/**
 Place Address in 'long' format
 */
@property (nonatomic,strong) NSString *formattedAddress;

/**
 Place common name, like `Rome`, `Napoli` or `Paris`
 */
@property (nonatomic,readonly,strong) NSString *placeName;

/**
 Initialize a new FNPlace from a dictionary retrieved from API, it's usually used for internal porpouse
 @warning dict must not be null
 @param dict dictionary must contain all necessary keys
 @returns  new FNPlace
 */
-(id)initWithDictionary:(NSDictionary *)dict;

/**
 Initialize a new FNPlace from an identifier, also it assigns a common name
 @warning dict must not be null
 @param identifier place code identifier
 @param label place common name
 @returns new FNPlace
 */
-(id)initWithIdentifier:(NSString *)identifier label:(NSString *)label;


/**
	Find a specific FNPlace from a general feed
	@param identifier Region identifier ie prov063
	@param feed the general feed
	@returns the specific FNPlace
 */
+(FNPlace *)findPlaceWithIdentifier:(NSString *)identifier fromFeed:(FNFeedBase *)feed;


@end
