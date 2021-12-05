/* -*-objc-*-
   NSCollectionView.h

   Copyright (C) 2013 Free Software Foundation, Inc.

   Author: Doug Simons (doug.simons@testplant.com)
           Frank LeGrand (frank.legrand@testplant.com)
   Date: February 2013
   
   This file is part of the GNUstep GUI Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/

#ifndef _GNUstep_H_NSCollectionView
#define _GNUstep_H_NSCollectionView

#import <GNUstepBase/GSVersionMacros.h>

#import <AppKit/NSDragging.h>
#import <AppKit/NSNibDeclarations.h>
#import <AppKit/NSView.h>

@class NSCollectionViewItem;
@class NSCollectionView;
@class NSCollectionViewLayout;

enum
{  
  NSCollectionViewDropOn = 0,
  NSCollectionViewDropBefore = 1,
};
typedef NSInteger NSCollectionViewDropOperation;

typedef NSString *NSCollectionViewSupplementaryElementKind;

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
@protocol NSCollectionViewDataSource <NSObject>
#if GS_PROTOCOLS_HAVE_OPTIONAL
@required
#endif
- (NSInteger) collectionView: (NSCollectionView *)collectionView
      numberOfItemsInSection: (NSInteger)section;

- (NSCollectionViewItem *) collectionView: (NSCollectionView *)collectionView
      itemForRepresentedObjectAtIndexPath: (NSIndexPath *)indexPath;
#if GS_PROTOCOLS_HAVE_OPTIONAL
@optional
#endif
- (NSInteger) numberOfSectionsInCollectionView: (NSCollectionView *)collectionView;

- (NSView *) collectionView: (NSCollectionView *)collectionView
             viewForSupplementaryElementOfKind: (NSCollectionViewSupplementaryElementKind)kind
                atIndexPath:(NSIndexPath *)indexPath;
@end
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
@protocol NSCollectionViewPrefetching <NSObject>
#if GS_PROTOCOLS_HAVE_OPTIONAL
@required
#endif
- (void)collectionView:(NSCollectionView *)collectionView prefetchItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
#if GS_PROTOCOLS_HAVE_OPTIONAL
@optional
#endif
- (void)collectionView:(NSCollectionView *)collectionView cancelPrefetchingForItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
@end
#endif

@protocol NSCollectionViewDelegate <NSObject>

#if GS_PROTOCOLS_HAVE_OPTIONAL
@optional
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
- (BOOL) collectionView: (NSCollectionView *)collectionView
         canDragItemsAtIndexPaths: (NSSet *)indexPaths
              withEvent: (NSEvent *)event;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
- (BOOL) collectionView: (NSCollectionView *)collectionView
  canDragItemsAtIndexes: (NSIndexSet *)indexes
              withEvent: (NSEvent *)event;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
- (BOOL) collectionView: (NSCollectionView *)collectionView
         writeItemsAtIndexPaths: (NSSet *)indexPaths
           toPasteboard: (NSPasteboard *)pasteboard;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
- (BOOL) collectionView: (NSCollectionView *)collectionView
    writeItemsAtIndexes: (NSIndexSet *)indexes
           toPasteboard: (NSPasteboard *)pasteboard;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
- (NSArray *) collectionView: (NSCollectionView *)collectionView
              namesOfPromisedFilesDroppedAtDestination: (NSURL *)dropURL
 forDraggedItemsAtIndexPaths: (NSSet *)indexPaths;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
- (NSArray *) collectionView: (NSCollectionView *)collectionView
              namesOfPromisedFilesDroppedAtDestination: (NSURL *)dropURL
    forDraggedItemsAtIndexes: (NSIndexSet *)indexes;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
- (NSImage *) collectionView: (NSCollectionView *)collectionView
              draggingImageForItemsAtIndexPaths: (NSSet *)indexPaths
                   withEvent: (NSEvent *)event
                      offset: (NSPointPointer)dragImageOffset;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
- (NSImage *) collectionView: (NSCollectionView *)collectionView
              draggingImageForItemsAtIndexes: (NSIndexSet *)indexes
                   withEvent: (NSEvent *)event
                      offset: (NSPointPointer)dragImageOffset;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
- (NSDragOperation) collectionView: (NSCollectionView *)collectionView
                      validateDrop: (id < NSDraggingInfo >)draggingInfo
                 proposedIndexPath: (NSIndexPath **)proposedDropIndexPath
                     dropOperation: (NSCollectionViewDropOperation *)proposedDropOperation;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
- (NSDragOperation) collectionView: (NSCollectionView *)collectionView
                      validateDrop: (id < NSDraggingInfo >)draggingInfo
                     proposedIndex: (NSInteger *)proposedDropIndex
                     dropOperation: (NSCollectionViewDropOperation *)proposedDropOperation;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
- (BOOL) collectionView: (NSCollectionView *)collectionView
             acceptDrop: (id < NSDraggingInfo >)draggingInfo
              indexPath: (NSIndexPath *)indexPath
          dropOperation: (NSCollectionViewDropOperation)dropOperation;
#endif

#if OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
- (BOOL) collectionView: (NSCollectionView *)collectionView
             acceptDrop: (id < NSDraggingInfo >)draggingInfo
                  index: (NSInteger)index
          dropOperation: (NSCollectionViewDropOperation)dropOperation;
#endif

@end


@interface NSCollectionView : NSView //<NSDraggingDestination, NSDraggingSource>
{
  NSArray *_content;
  IBOutlet NSCollectionViewItem *itemPrototype;
  NSMutableArray *_items;
  
  BOOL _allowsMultipleSelection;
  BOOL _isSelectable;
  NSIndexSet *_selectionIndexes;
  
  NSArray *_backgroundColors;
  IBOutlet id <NSCollectionViewDelegate> delegate;
  
  NSSize _itemSize;
  NSSize _maxItemSize;
  NSSize _minItemSize;
  CGFloat _tileWidth;
  CGFloat _verticalMargin;
  CGFloat _horizontalMargin;

  NSUInteger _maxNumberOfColumns;
  NSUInteger _maxNumberOfRows;
  NSUInteger _numberOfColumns;
  
  NSDragOperation _draggingSourceOperationMaskForLocal;
  NSDragOperation _draggingSourceOperationMaskForRemote;
  
  NSUInteger _draggingOnRow;
  NSUInteger _draggingOnIndex;

  NSCollectionViewLayout *_collectionViewLayout;
}

- (BOOL) allowsMultipleSelection;
- (void) setAllowsMultipleSelection: (BOOL)flag;

- (NSArray *) backgroundColors;
- (void) setBackgroundColors: (NSArray *)colors;

- (NSArray *)content;
- (void)setContent:(NSArray *)content;

- (id < NSCollectionViewDelegate >) delegate;
- (void) setDelegate: (id < NSCollectionViewDelegate >)aDelegate;

- (NSCollectionViewItem *) itemPrototype;
- (void) setItemPrototype: (NSCollectionViewItem *)prototype;

- (NSSize) maxItemSize;
- (void) setMaxItemSize: (NSSize)size;

- (NSUInteger) maxNumberOfColumns;
- (void) setMaxNumberOfColumns: (NSUInteger)number;

- (NSUInteger) maxNumberOfRows;
- (void) setMaxNumberOfRows: (NSUInteger)number;

- (NSSize) minItemSize;
- (void) setMinItemSize: (NSSize)size;

- (BOOL) isSelectable;
- (void) setSelectable: (BOOL)flag;

- (NSIndexSet *) selectionIndexes;
- (void) setSelectionIndexes: (NSIndexSet *)indexes;

#if OS_API_VERSION(MAC_OS_X_VERSION_10_11, GS_API_LATEST)
- (NSCollectionViewLayout *) collectionViewLayout;
- (void) setCollectionViewLayout: (NSCollectionViewLayout *)layout;
#endif

- (NSRect) frameForItemAtIndex: (NSUInteger)index;
- (NSCollectionViewItem *) itemAtIndex: (NSUInteger)index;
- (NSCollectionViewItem *) newItemForRepresentedObject:(id)object;

- (void) tile;

- (void) setDraggingSourceOperationMask: (NSDragOperation)dragOperationMask 
                               forLocal: (BOOL)localDestination;
							   
- (NSImage *) draggingImageForItemsAtIndexes: (NSIndexSet *)indexes
                                   withEvent: (NSEvent *)event
                                      offset: (NSPointPointer)dragImageOffset;


@end

#endif /* _GNUstep_H_NSCollectionView */
