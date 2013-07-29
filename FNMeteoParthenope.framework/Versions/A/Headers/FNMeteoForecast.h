/** @class  FNMeteoForecast FNMeteoForecast.h
 *  @brief  Class object representing a weather forecast.
 *  @author Fabio Nisci - http://www.fabiosoft.com
 *  @details Class object representing a weather forecast based on output, default GENERAL, all properties that are not compliant with output are null.
 *  @date   July 2013
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "FNDefines.h"
#import "FNForecastDetail.h"

/**
 * @memberof FNMeteoForecast
 * `General` output. Default setting
 */
static NSString *const GENERAL = @"gen";

// "gen": "visualizzazione generale"

//-- CONSTS output for WRF3 Meteo bassa risoluzione 144h
//-- WRF5 Meteo alta risoluzione 24h---//
// "id": "ws10", "unit": "knt", "label": "Velocita del vento a 10"
static NSString *const WINDSPEED = @"ws10";
//   "id": "wd10", "unit": "°N", "label": "Direzione del vento a 10m"
static NSString *const WINDDIR = @"wd10";
//  "id": "u10m", "unit": "m/s", "label": "Componente u della velocita del vento a 10m"
static NSString *const UWINDSPEED = @"u10m";
//  "id": "v10m", "unit": "m/s", "label": "Componente v della velocita del vento a 10m"
static NSString *const VWINDSPEED = @"v10m";
//  "id": "t2c", "unit": "°C","label": "Temperatura in Celsius"
static NSString *const TEMPC = @"t2c";
//  "id": "slp","unit": "hPa", "label": "Pressione a livello del mare"
static NSString *const PRESSSEA = @"slp";
//  "id": "clf","unit": "%","label": "Frazione Copertura Nuvolosa"
static NSString *const NUVFRAC = @"clf";
//  "id": "crh","unit": "mm","label": "Pioggia Cumulata Oraria"
static NSString *const PIOGGORA = @"crh";
//   "id": "rh2","unit": "%","label": "Umidità relativa a 2m"
static NSString *const HUMIDREL = @"rh2";
// data/ora della previsione sotto @attributes in formato: yyyyMMdd'Z'HH
static NSString *const DATAPREV = @"date";
//----------------------------------------


//-- CONSTS output for CHM3 Qualita' dell'aria bassa risoluzione 120h---//
// "caqi": "Indice di qualita' dell'aria"
static NSString *const AIR_QUALITY_INDEX = @"caqi";
// "co": "monossido di carbonio"
static NSString *const MONOX_CARBON = @"co";
// "no2": "biossido di azoto"
static NSString *const NITRO_DIOXIDE = @"no2";
// "o3": "ozono"
static NSString *const OZONE = @"o3";
// "pm10": "particolato 10 micron"
static NSString *const PART_10MICRO = @"pm10";
// "pm25": "particoalto 2.5 micron"
static NSString *const PART_25MICRO = @"pm25";
// "so2": "anidride solforosa"
static NSString *const SULFUR_DIOXIDE = @"so2";
//--------------------------


//-- CONSTS output for CLM3 Vento altissima risoluzione 24h---//
// "gen": "visualizzazione generale"
// "wind": "campo vettoriale del vento",
static NSString *const WIND_VECT = @"wind";
// "wn1": "campo versoriale del vento",
static NSString *const WIND_VERS = @"wn1";
// "wn2": "tendenza e direzione nell'ora successiva",
static NSString *const WIND_TREND = @"wn2";
// "wn3": "campo versoriale, scala beaufort
static NSString *const WIND_VERS_BEAU = @"wn3";
//--------------------------

//-- CONSTS output for LPD3 Diffusione e trasporto inquinanti 120h---//
// "gen": "visualizzazione generale"
// "conc": "Concentrazione"
static NSString *const CONCENTRATION = @"conc";
//----------------------------------

//-- CONSTS output for RMS3: "Dinamica costiera 120h---//
// "gen": "visualizzazione generale"
// "cur": "Corrente superficiale",
static NSString *const SURFACE_CURR = @"cur";
// "sss": "Salinita' superficiale"
static NSString *const SURFACE_SALT = @"sss";
// "sst": "Temperatura superficiale"
static NSString *const SURFACE_TEMP = @"sst";
//----------------------------------


//-- CONSTS output for WW33: "Moto ondoso bassa risoluzione 144h---//
// "gen": "visualizzazione generale",
// "wa1": "periodo e direzione del fronte d'onda",
static NSString *const TIME_WAVE = @"peakp";
// "wav": "altezza significativa e direzione del fronte d'onda",
static NSString *const HEIGHT_WAVE = @"hs";
// "peakd" direzione del fronte d'onda
static NSString *const DIR_WAVE = @"peakd";

//----------------------------------


@interface FNMeteoForecast : NSObject

/**
 * @name Forecast base informations, always available
 */

/**
 Region identifier
 */
@property (nonatomic,strong) NSString *idplace; //id region


/**
 Region common name (i.e. Paris, Rome or Napoli)
 */
@property (nonatomic,strong) NSString *label; //nome luogo

/**
 Date measured forecast
 */
@property (nonatomic,strong) NSDate *data;


/**
 * @name WRF 3/5 properties
 */

/**
 Wind Speed default unit: knt
 */
@property (nonatomic,strong) FNForecastDetail *speedVento;//knt

/**
 Wind direction in degree default unit: °N
 */
@property (nonatomic,strong) FNForecastDetail *dirVento;//°N

/**
 Wind vector U
 */
@property (nonatomic,strong) FNForecastDetail *UspeedVento;

/**
 Wind vector V
 */
@property (nonatomic,strong) FNForecastDetail *VspeedVento;


/**
 Temperature in celsius
 */
@property (nonatomic,strong) FNForecastDetail *temperaturaC;//c

/**
 Max temperature in celsius
 */
@property (nonatomic,strong) FNForecastDetail *temperaturaMaxC;//c

/**
 Min temperature in celsius
 */
@property (nonatomic,strong) FNForecastDetail *temperaturaMinC;//c

/**
 Air pressure default unit: hpa
 */
@property (nonatomic,strong) FNForecastDetail *pressione;//hpa

/**
 Cloud coverage %
 */
@property (nonatomic,strong) FNForecastDetail *copNuvolosa;// %

/**
 Hourly rain default unit: mm
 */
@property (nonatomic,strong) FNForecastDetail *pioggiaOra;// mm

/**
 Humidity %
 */
@property (nonatomic,strong) FNForecastDetail *umidita;// %

/**
 Real temperature feel in celsius aka HX in celsius
 */
@property (nonatomic,strong) FNForecastDetail *tempPercepita;//HX //c

/**
 Apparent temperature in celsius aka HI+WC aka RealFeel©
 */
@property (nonatomic,strong) FNForecastDetail *tempApparente;//HI + WC - usare questa per le previsioni //c

/**
 Summer Simmer Index aka Heat index value (HI)
 */
@property (nonatomic,strong) FNForecastDetail *tempIndiceCalore;//SSI

/**
 region GPS coordinates
 */
@property (nonatomic,strong) CLLocation *coords;

/**
 * @name CHM3 properties
 */
/**
 Air Quality Index
 */
@property (nonatomic,strong) FNForecastDetail *airQualityIndex;

/**
 Carbon Monoxide
 */
@property (nonatomic,strong) FNForecastDetail *monoxCarbon;

/**
 Nitrogen Dioxide
 */
@property (nonatomic,strong) FNForecastDetail *nitroDioxide;

/**
 Ozone
 */
@property (nonatomic,strong) FNForecastDetail *ozone;

/**
 Particulate 10 micron
 */
@property (nonatomic,strong) FNForecastDetail *part10micro;

/**
 Particulate 2.5 micron
 */
@property (nonatomic,strong) FNForecastDetail *part25micro;

/**
 Sulfur Dioxide
 */
@property (nonatomic,strong) FNForecastDetail *sulfurDioxide;


/**
 * @name CML3 properties
 * no propertis available now
 */

/**
 * @name LPD3 properties
 */

/**
 Concentration
 */
@property (nonatomic,strong) FNForecastDetail *concentration;


/**
 * @name RMS3 properties
 */

/**
 * Surface current
 */
@property (nonatomic,strong) FNForecastDetail *surfaceCurrent;

/**
 Surface salinity
 */
@property (nonatomic,strong) FNForecastDetail *surfaceSalinity;

/**
 Surface temperature in celsius
 */
@property (nonatomic,strong) FNForecastDetail *surfaceTemperature;


/**
 * @name WW33 properties
 */

/**
 * Period and direction of the wavefront
 */
@property (nonatomic,strong) FNForecastDetail *timeWave;

/**
 * Significant wave height and direction of the wave front
 */
@property (nonatomic,strong) FNForecastDetail *heightWave;

/**
 * @name Methods
 */
/**
 Initialize a weather forecast from dictionary (based on model)
 @param dict dictionary based on model keys and values
 @param model FNMeteoModel. Indicates what model use to initialize
 @returns a weather object with all details
 */
-(id)initWithDict:(NSDictionary *)dict model:(NSUInteger)model;

/**
 Initialize a weather forecasts based on timeseries (all hours in 5 days)
 @param dict dictionary based on model keys and values
 @param BaseUnits array of measurements units
 @param model FNMeteoModel. Indicates what model use to initialize
 @returns a weather object with all details
 */
-(id)initWithTimeseries:(NSDictionary *)dict withUnits:(NSArray *)BaseUnits model:(NSUInteger)model;

+(NSString *)fromTodayToTimeseriesStampStatic;
/**
 Convert a date to string formatted timestamp accepted from API
 @param theDate NSDate date to convert
 @returns date formatted as string with format: yyyyMMdd'Z'HH
 */
+(NSString *)fromDateToTimeseriesStamp:(NSDate *)theDate;

/**
 Get a Dictionary based information. Convert `Summer Simmer Index` to more detailed informations.
 @param SSI `Summer Simmer Index` aka tempIndiceCalore
 @returns keys available: __label__: short description
 __desc__: long description
 */
-(NSDictionary *)getStringFromSSI:(NSNumber *)SSI;

/**
 Convert a `string` date to a real `date` object without considering minutes
 @param stringdate formatted as string with format: yyyyMMdd'Z'HH
 @returns real `NSDate` object
 */
-(NSDate *)convertDateNOminutes:(NSString *)stringdate;

/**
 Convert a `string` date to a real `date` object
 @param stringDate formatted as string with format: yyyyMMdd'Z'HHmm
 @returns real `NSDate` object
 */
-(NSDate *)convertDate:(NSString *)stringDate;

/**
 Get a dictionary based information about texual weather information
 @param lang output language, it could be __it__ or __en__
 @param clf cloudy coverage
 @param crh hourly rain
 @param data a date for correct coutput information
 @param night include night image?
 @returns dictinary keys: __iconURL__: url remote icon __iconLbl__:texual weather information
 */
-(NSDictionary*)getSkyIconTextWithLang:(NSString*)lang nuvFrac:(float)clf pioggiaOra:(float)crh data:(NSDate *)data withNight:(BOOL)night;

/**
 Wind weather information and status
 @param lang output language, it could be __it__ or __en__
 @param ws10 wind speed in knots
 @returns string information about wind
 */
-(NSString*)knotsToTextFromLang:(NSString*)lang speedVento:(float)ws10;

/**
 Wind weather direction degree to text
 @param wd10 wind direction at 10 meters
 @returns string information about carinals points like North, South, etc... shorted
 */
-(NSString*)windDirToText:(float)wd10;

/**
 Wind vectors to degrees
 @param u10m u wind component
 @param v10m v wind component
 @returns degree angle
 */
-(float) uvToNDegs:(float )u10m v10m:(float)v10m;

/**
 Wind vectors to knots
 @param u10m u wind component
 @param v10m v wind component
 @returns degree angle
 */
-(float) uvToKnots:(float )u10m v10m:(float)v10m;


@end
