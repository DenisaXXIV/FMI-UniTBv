using AutoMapper;
using Hotel_WPF.BL.Interfaces;
using Hotel_WPF.DAL.Entities;
using Hotel_WPF.DAL.Interfaces;
using Hotel_WPF.TL.DTO;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hotel_WPF.BL.Classes
{
    public class ImageLogic : IEntityLogic<ImageDTO>
    {
        private readonly IHotelRepository<Image> _imagesRepository;
        private readonly IMapper _mapper;

        public ImageLogic(IHotelRepository<Image> imagesRepository, IMapper mapper)
        {
            _imagesRepository = imagesRepository;
            _mapper = mapper;
        }

        public async Task Add(ImageDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Image>(entityDTO);
                await _imagesRepository.Add(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task<List<ImageDTO>> GetAll()
        {
            var results = _mapper.Map<List<ImageDTO>>(await _imagesRepository.GetAll());
            return results;
        }

        public async Task<ImageDTO> GetByName(string name)
        {
            if (name == null)
            {
                throw new ArgumentNullException(nameof(name));
            }
            ImageDTO result;
            try
            {
                var results = _mapper.Map<List<ImageDTO>>(await _imagesRepository.GetAll());
                result = results.FirstOrDefault(a => a.Name == name);
                if (result == null)
                {
                    throw new DbUpdateException();
                }
                return result;
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }

        public async Task Remove(ImageDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                await _imagesRepository.Delete(entityDTO.IdImage);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }



        public async Task Update(ImageDTO entityDTO)
        {
            if (entityDTO == null)
            {
                throw new ArgumentNullException(nameof(entityDTO));
            }
            try
            {
                var entity = _mapper.Map<Image>(entityDTO);
                await _imagesRepository.Update(entity);
            }
            catch (DbUpdateException)
            {
                throw;
            }
        }
    }
}
