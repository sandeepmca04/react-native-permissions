#import <React/RCTBridgeModule.h>

typedef enum {
  RNPermissionStatusNotAvailable = 0,
  RNPermissionStatusNotDetermined = 1,
  RNPermissionStatusRestricted = 2,
  RNPermissionStatusDenied = 3,
  RNPermissionStatusAuthorized = 4,
} RNPermissionStatus;

@protocol RNPermissionHandler <NSObject>

@optional

+ (NSArray<NSString *> * _Nullable)usageDescriptionKeys;

@required

- (void)checkWithResolver:(nullable void (^)(RNPermissionStatus status))resolve
             withRejecter:(void (^ _Nullable)(NSError * _Nullable error))reject;

- (void)requestWithOptions:(NSDictionary * _Nullable)options
              withResolver:(nullable void (^)(RNPermissionStatus status))resolve
              withRejecter:(void (^ _Nullable)(NSError * _Nullable error))reject;

@end

@interface RNPermissionsManager : NSObject <RCTBridgeModule>

+ (bool)hasBackgroundModeEnabled:(nullable NSString *)mode;

+ (void)logErrorMessage:(nullable NSString *)message;

+ (bool)hasBeenRequestedOnce:(nullable id<RNPermissionHandler>)handler;

@end
