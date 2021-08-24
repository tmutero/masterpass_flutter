//
//  MPMasterPass.h
//  MasterPassKit
//
//  Created by Ferdie Danzfuss on 2016/03/29.
//  Copyright © 2016 Mobilica (Pty) Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MPWaitingViewController.h"
#import "MPTransitioningDelegate.h"
#import "MPGlobals.h"

@protocol MMNixDelegate;

typedef NS_ENUM(NSInteger, MPError) {
    MPErrorNetworkError,
    MPErrorExceptionOccored,
    MPErrorPaymentError,
    MPErrorOTPError,
    MPErrorInvalidCodeParameter,
    MPErrorInvalidApiKeyParameter,
    MPErrorSecureCodeNotSupported,
    MPErrorCodeNotVariableAmount
};


@protocol MPMasterPassDelegate <NSObject>

@required
-(void)masterpassUserDidCancel;
@required
-(void)masterpassPaymentSucceededWithTransactionReference:(NSString *)transactionReference;
@required
-(void)masterpassError:(MPError)error;
@required
-(void)masterpassPaymentFailedWithTransactionReference:(NSString *)transactionReference;
@required
-(void)masterpassInvalidCode;
@required
-(void)masterpassUserRegistered;
@required
-(void)masterpassUserCompletedWallet;

@end


@interface MPMasterPass : NSObject <MMNixDelegate>

+ (void)load;
-(void)showLoadingDialogFromController:(UIViewController *)presentingController;
-(void)hideLoadingDialog;

-(void)checkoutWithCode:(NSString *)code amount:(NSString *)amount apiKey:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate;
-(void)checkoutWithCode:(NSString *)code amount:(NSString *)amount apiKey:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate preMSISDN:(NSString *)preMSISDN;
-(void)checkoutWithCode:(NSString *)code amount:(NSString *)amount apiKey:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate customerId:(NSString*)customerId;
-(void)checkoutWithCode:(NSString *)code amount:(NSString *)amount apiKey:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate preMSISDN:(NSString *)preMSISDN customerId:(NSString*)customerId;

-(void)preRegister:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate;
-(void)preRegister:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate preMSISDN:(NSString *)preMSISDN;
-(void)preRegister:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate customerId:(NSString*)customerId;
-(void)preRegister:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate preMSISDN:(NSString *)preMSISDN customerId:(NSString*)customerId;

-(void)WalletManagement:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate;
-(void)WalletManagement:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate preMSISDN:(NSString *)preMSISDN;
-(void)WalletManagement:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate customerId:(NSString*)customerId;
-(void)WalletManagement:(NSString *)apiKey system:(MPSystem)system controller:(UIViewController *)presentingController delegate:(id<MPMasterPassDelegate>)delegate preMSISDN:(NSString *)preMSISDN customerId:(NSString*)customerId;

-(void)deregisterUser;

-(NSString *)getLibNixApiVersion;
//TODO remove, for dubugging only
-(void)showScreen:(NSString *)storybaordId fromController:(UIViewController *)presentingController;

-(void)reset;

+(void)printFonts;

+(void)loadCodeInfo:(MPWaitingViewController*) waitingViewController;

@end
