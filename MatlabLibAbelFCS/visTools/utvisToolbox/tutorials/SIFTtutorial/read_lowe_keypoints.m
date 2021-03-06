function [ pos, scale, orient, desc ] = read_lowe_keypoints( fname, mask )

% [ pos, scale, orient, desc ] = read_lowe_keypoints( fname, mask )
%
% Read a keypoint file generated by David Lowe's keypoints demo.
%
% Input:
% fname - the filename of the keypoint file, with path but without the 
%   extension .key.
% mask - a mask to filter keypoints before returning them.
%
% Output:
% pos - an Nx2 matrix containing the (x,y) coordinates of the keypoints
%   stored in rows.
% scale - an Nx3 matrix with rows describing the scale of each keypoint (i.e.,
%   first column specifies the octave, second column specifies the interval, and
%   third column specifies sigma).
% orient - a Nx1 vector containing the orientations of the keypoints [-pi,pi).
% desc - an Nx128 matrix with rows containing the feature descriptors 
%   corresponding to the keypoints.
%
% Thomas F. El-Maraghi
% May 2004

[fid,msg] = fopen( [fname,'.key'], 'r' );
if fid == -1
   error( msg );
end

[head count] = fscanf( fid, '%d', 2 );

pos = zeros(head(1),2);
orient = zeros(head(1),1);
scale = zeros(head(1),1);
desc = zeros(head(1),head(2));

for k = 1:head(1)
   x = fscanf( fid, '%f', 2 )';
   pos(k,:) = [x(2) x(1)];
   scale(k) = fscanf( fid, '%f', 1 );
   orient(k) = fscanf( fid, '%f', 1 );
   desc(k,:) = fscanf( fid, '%d', head(2) )';   
end

fclose( fid );

if exist('mask')
   pts = round(pos);
   keep = zeros(size(pts,1),1);
   for k = 1:size(pts,1)          
      if mask(pts(k,2), pts(k,1)) == 1
         keep(k) = 1;
      end
   end
   k = find(keep == 1);
   pos = pos(k,:);
   scale = scale(k);
   orient = orient(k);
   desc = desc(k,:);
end

pos = pos + 1;
