/** @class  FNForecastDetail FNForecastDetail.h
 *  @brief  Class object representing a weather data unit and Value.
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Class object representing a weather data unit and Value. It makes easy to access to Value and its unit.
 *  @date   July 2013
 */


#import "FNObjDetail.h"

@interface FNForecastDetail : FNObjDetail <NSCoding>

/**
 String data measurement unit
 */
@property (nonatomic,strong) NSString *unit;

/**
 The Value
 */
@property (nonatomic,strong) NSNumber *value;


/**
 Given a unit ID, usually a constant and all units available array return the correct unit like mm or % ...etc
 @param theID a constant that rapresent unit code like TEMPC or WINDSPEED
 @param units array of all units dictionary
 @returns the units measurement to assign, in string
 */
+ (NSString *)findUnitFromID:(NSString *)theID units:(NSArray *)units;

/**
 Initialize a new FNForecastDetail object
 @param unit unit to assign to the Value
 @param value the Value
 @returns new FNForecastDetail object
 */
- (id)initWithUnit:(NSString *)unit value:(NSNumber *)value;

/**
 Helper method that converts NSNumber Value to a float
 @returns Value as a float
 */
- (float)floatValue;

/**
 Helper method for return Value simply
 @returns Value as NSNumber
 */
- (NSNumber *)numberValue;


@end
