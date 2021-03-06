#include "imageProcess.hpp"

ALLEGRO_BITMAP *ImageProcess::load_bitmap_at_size(const char *filename, int w, int h){
		ALLEGRO_BITMAP *resized_bmp, *loaded_bmp, *prev_target;

		// 1. create a temporary bitmap of size we want
		resized_bmp = al_create_bitmap(w, h);
		if (!resized_bmp) return NULL;

		// 2. load the bitmap at the original size
		loaded_bmp = al_load_bitmap(filename);
		if (!loaded_bmp)
		{
			al_destroy_bitmap(resized_bmp);
			return NULL;
		}

		// 3. set the target bitmap to the resized bmp
		prev_target = al_get_target_bitmap();
		al_set_target_bitmap(resized_bmp);

		// 4. copy the loaded bitmap to the resized bmp
		al_draw_scaled_bitmap(loaded_bmp,
			0, 0,                                // source origin
			al_get_bitmap_width(loaded_bmp),     // source width
			al_get_bitmap_height(loaded_bmp),    // source height
			0, 0,                                // target origin
			w, h,                                // target dimensions
			0                                    // flags
		);

		// 5. restore the previous target and clean up
		al_set_target_bitmap(prev_target);
		al_destroy_bitmap(loaded_bmp);

		return resized_bmp;      
}